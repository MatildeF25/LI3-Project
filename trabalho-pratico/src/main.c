
/**
 * @file main.c
 * 
 * Este ficheiro contém a função responsável para a execução do programa
*/
//#include "../libs/queries.h "
#include <stdio.h>
#include "../include/users.h"
#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/queries.h"
#include "../include/prints.h"


/**
 * @brief         Funcão auxiliar que é usada para concatenar duas strings: "path" e "file"
 * 
 * @param path     caminho para a pasta
 * @param file     nome do ficheiro
 *
 * @return        o caminho para o ficheiro da pasta 'path' do ficheiro 'file'
 */
char* pointer_file (char *path, char *file){
  char *file_name = malloc(strlen(path) + strlen(file) + 2); // + 2 por causa do \0 e pq n sabes se o path acaba em / ou nao
  
  strcat(file_name, path);
  if (path[strlen(path)] != '/')
    strcat(file_name,"/");
  strcat(file_name, file);

  return file_name; 
}


/**
 * @brief         Funcão auxiliar que verifica se uma string é um número
 * 
 * @param str     String dada
 *
 * @return         1 se a string de entrada "str" contiver algum caractere que não seja um dígito (0-9), caso contrário, retorna 0.
 */
int str_is_num (char* str){
    unsigned i;
    int p=0;
    for(i=0; i<strlen(str); i++){
        if (str[i]<'0' || str[i]>'9'){
            p=1;
            return p;
        }
    }
    return p;
}


int main (int argc, char **argv) {
    
    char *users = pointer_file(argv[1],"users.csv"), *drivers =  pointer_file(argv[1],"drivers.csv"), *rides = pointer_file(argv[1],"rides.csv");
    
    USER_HT* u_ht = create_UserHt(users);
    DRIVERS_HT* d_ht = create_DriversHt(drivers);
    RIDES_HT* r_ht = create_RidesHt(rides, u_ht, d_ht);

    free(users);
    free(drivers);
    free(rides);
   
    if (argc == 3){
                
        FILE *file_query;
        file_query = fopen(argv[2], "r");
        
        if(file_query == NULL)
        {
            perror("Erro:");
            exit(1);
        }
        char line[100];
        int buffer_size = 100;
        int num = 0;
       
        while(fgets(line, buffer_size, file_query))
        {
            char *query, *n_query, *query_arg, *arg1, *arg2, *arg3;
            query = strdup(line);
            n_query = strsep(&query, " ");
            query_arg = strsep(&query, "\n");
            //unsigned i;
            num++;
            switch (n_query[0])
            {
            case '1':
                if(str_is_num(query_arg)==0){
                    q1driver(d_ht,atoi(query_arg),num);
                }
                else{
                    q1users(u_ht, query_arg,num);
                    
                }
                break;
            case '2':
                q2(d_ht,atoi(query_arg),num);
                break;
            case '3':
                q3(u_ht,atoi(query_arg),num);
                break;
            case '4':
                q4(r_ht,d_ht,query_arg,num);
                break;
            case '5':
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q5(r_ht,d_ht,arg1, arg2,num);
                break;
            case '6':
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg," ");
                arg3 = strsep(&query_arg,"\n");
                q6 (r_ht, arg1 , arg2, arg3,num);
                break;
            case '7':
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                
                if(avaliacao_t_cidade(r_ht, d_ht, arg2)==0){
                    q7_vazia (d_ht,atoi(arg1),num);
                }
                else{
                    q7 (d_ht,atoi(arg1),num);  
                }
                break;
            case '8':
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q8 (r_ht,d_ht,u_ht,*arg1,atoi(arg2),num);  
                break;
            case '9':
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q9 (r_ht,arg1,arg2,num);   
                break; 
            default:
                break;
            }
        }

        delete_rides_hash(r_ht);
        delete_users_hash(u_ht);
        delete_drivers_hash(d_ht);
        
    }
    else if (argc == 2){

        int running = 1;
    
    
        while (running) {
            char* query = malloc(200), *n_query, *query_arg, *arg1, *arg2, *arg3;

           
            printMenu();
           
            scanf("%200[^\n]s", query);
            
           
            while ( getchar() != '\n' );

            n_query = strsep(&query, " ");
            query_arg = strsep(&query, "\n");
            

                switch(n_query[0]) {
                    case '0':
                        printf("A sair....\n");
                        running = 0;
                        break;
                    case '1':
                        if(str_is_num(query_arg)==0){
                            print_q1driver(d_ht,atoi(query_arg));
                        }
                        else{
                            print_q1users(u_ht,query_arg);
                        }
                        break;
                    case '2':
                        print_q2(d_ht,atoi(query_arg));
                        break;
                    case '3':
                        print_q3(u_ht,atoi(query_arg));
                        break;
                    case '4':
                        print_q4(r_ht,d_ht,query_arg);
                        break;
                    case '5':
                        arg1 = strsep(&query_arg," ");
                        arg2 = strsep(&query_arg,"\n");
                        print_q5(r_ht,d_ht,arg1, arg2);
                        break;
                    case '6':
                        arg1 = strsep(&query_arg," ");
                        arg2 = strsep(&query_arg," ");
                        arg3 = strsep(&query_arg,"\n");
                        print_q6 (r_ht, arg1 , arg2, arg3);
                        break;
                    case '7':
                        arg1 = strsep(&query_arg," ");
                        arg2 = strsep(&query_arg,"\n");
                        if(avaliacao_t_cidade(r_ht, d_ht, arg2)==0){
                            printf("\n");
                        }
                        else{
                            print_q7 (d_ht, atoi(arg1));
                        }
                        break;  
                    case '8':
                        arg1 = strsep(&query_arg," ");
                        arg2 = strsep(&query_arg,"\n");
                        print_q8 (r_ht,d_ht,u_ht,arg1,atoi(arg2));  
                break;        
                    case '9':
                        arg1 = strsep(&query_arg," ");
                        arg2 = strsep(&query_arg,"\n");
                        print_q9 (r_ht,arg1,arg2);   
                    default:
                        break;
                }
        }
    }  
}