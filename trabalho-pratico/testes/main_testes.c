/**
 * @file main_testes.c
 * 
 * Este ficheiro contém a função responsável para a execução do programa de testes
*/

#include <stdio.h>
#include "../include/users.h"
#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/queries.h"
#include "../include/prints.h"


/**
 * @brief         Funcão auxiliar que verifica se o conteúdo de dois ficheiros é igual
 * 
 * @param file1   caminho para o ficheiro
 * @param file2   caminho para o ficheiro
 * 
 * @return        0, se econtrar uma diferença ou se tiver algum problema ao abrir algum ficheiro
 *                1, se não encontrar diferenças, indicando os ficheiros que são iguais
 */
int compareFiles(const char* file1, const char* file2){
FILE *fp1,*fp2;
int ch1, ch2;


fp1 = fopen(file1, "r");
if (fp1 == NULL) {
    fprintf(stderr, "Can't open file %s for reading\n", file1);
    return 0;
}

fp2 = fopen(file2, "r");
if (fp2 == NULL) {
    fprintf(stderr, "Can't open file %s for reading\n", file2);
    fclose(fp1);
    return 0;
}


for (ch1 = fgetc(fp1),ch2 = fgetc(fp2); ch1 != EOF && ch2 != EOF; ch1 = fgetc(fp1),ch2 = fgetc(fp2)) {
    //printf("%c %c\n",ch1,ch2);
    if (ch1 != ch2) {
        fclose(fp1);
        fclose(fp2);
        return 0;
    }
}

if (ch1 != EOF || ch2 != EOF) {
    //printf("ola\n");
    fclose(fp1);
    fclose(fp2);
    return 0;
}

fclose(fp1);
fclose(fp2);
return 1;
}

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

  return file_name; // n te esqueças de dar free a isto no final
}

/**
 * @brief         Funcão auxiliar que verifica se uma string é um número
 *   Rides r_a = (Rides) a;
  Rides r_b = (Rides) b;

  int distA = r_a->distance;
  int distB = r_b->distance;

  if (distA==distB && datas_iguais(r_a->date,r_b->date)==1){
    return (r_b->id - r_a->id);
  }

  if(distA==distB){
    return compareDates(r_b->date,r_a->date);
  }
  
  return (distB - distA);
}

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


int teste_queries(int argc, char **argv) {
        clock_t start, end;
        double cpu_time_used;
        
        char *users = pointer_file(argv[1],"users.csv"), *drivers =  pointer_file(argv[1],"drivers.csv"), *rides = pointer_file(argv[1],"rides.csv");
        
        start = clock();
        USER_HT* u_ht = create_UserHt(users);
        DRIVERS_HT* d_ht = create_DriversHt(drivers);
        RIDES_HT* r_ht = create_RidesHt(rides, u_ht, d_ht);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tempo de parsing: %f segundos\n", cpu_time_used );

        free(users);
        free(drivers);
        free(rides);

       

        FILE *file_query;
        file_query = fopen(argv[2], "r");
        
        if(file_query == NULL)
        {
            printf("%s\n", argv[1]);
            perror("Erro:");
            exit(1);
        }
        char line[100];
        int buffer_size = 100;
        int num = 0;
        char produced_file[100];
        char expected_file[100];
        
        while(fgets(line, buffer_size, file_query))
        {
            char *query, *n_query, *query_arg, *arg1, *arg2, *arg3;
            query = strdup(line);
            n_query = strsep(&query, " ");
            query_arg = strsep(&query, "\n");
            num++;
            switch (n_query[0]){
            case '1':
                if(str_is_num(query_arg)==0){
                    start = clock();
                    q1driver(d_ht,atoi(query_arg),num);
                    end = clock();
                    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 1: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                }
                else{
                    start = clock();
                    q1users(u_ht, query_arg,num);
                    end = clock();
                    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 1: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                }
                break;
            case'2':
                start = clock();
                q2(d_ht,atoi(query_arg),num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file, "Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 2: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;
            case'3':
                start = clock();
                q3(u_ht,atoi(query_arg),num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file, "Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 3: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;
            case'4':
                start = clock();
                q4(r_ht,d_ht,query_arg,num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                   if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 4: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file)); 
                break;
            case'5':
                start = clock();
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q5(r_ht,d_ht,arg1, arg2,num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file, "Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 5: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break; 
            case'6':
                start = clock();
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg," ");
                arg3 = strsep(&query_arg,"\n");
                q6 (r_ht, arg1 , arg2, arg3,num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 6: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;  
            case'7':
                start = clock();
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                if(avaliacao_t_cidade(r_ht, d_ht, arg2)==0){
                    q7_vazia (d_ht,atoi(arg1),num);
                }
                else{
                    q7 (d_ht,atoi(arg1),num);  
                }
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file, "Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 7: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;  
            case '8':
                start = clock();
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q8 (r_ht,d_ht,u_ht,arg1,atoi(arg2),num);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                    if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 8: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;    
            case'9':
                start = clock();
                arg1 = strsep(&query_arg," ");
                arg2 = strsep(&query_arg,"\n");
                q9 (r_ht,arg1,arg2,num); 
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

                    sprintf(produced_file,"Resultados/command%d_output.txt", num);
                    sprintf(expected_file, "Resultados-esperados/command%d_output.txt", num);
                    
                   if (compareFiles(produced_file,expected_file)==1 && cpu_time_used<10) {
                        printf("Esta query está correta e executa em tempo útil:\n");
                    }
                    else{
                        printf("Esta query está incorreta:\n");
                    } 
                    
                    printf("Tempo de execução da query 9: %f segundos\n", cpu_time_used );
                    memset(produced_file, 0, sizeof(produced_file));
                    memset(expected_file, 0, sizeof(expected_file));
                break;            
            default:
                break;    
        }
        }

        delete_rides_hash(r_ht);
        delete_users_hash(u_ht);
        delete_drivers_hash(d_ht);

        return 0;
}


    int main(int argc, char **argv) {

    teste_queries(argc, argv);

    return 0;
    }


