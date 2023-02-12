// #include "../libsanitizer.spec"/queries.h"

/**
 * @file queries.c
 * Este ficheiro contém as funções que executam as queries
*/

#include "../include/queries.h"



#define MAX_LINE 2048

/**
 * @brief Função que executa query 1 se o argumento for um username de um user e escreve num ficheiro txt a resposta à query 1 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) dos users 
 * @param username string que será o username (users.csv)
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */

void q1users (USER_HT* lista, char* username, int num){
    User u = q1u(lista, username);
    
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    
    FILE *out_file = fopen(file_name, "w");

    if (u == NULL || strcmp(getUserAccountStatus(u),"INACTIVE")==0){
        fprintf(out_file,"");
    }
    else{
        fprintf(out_file, "%s;%c;%d;%.3lf;%d;%.3lf\n", getUserXName(u), getUserGender(u), idade(getBirthDate(u)), (double)(getScore_u(u)/getn_viagensU(u)), getn_viagensU(u), getTotal_gasto(u));
    }
    fclose(out_file);
}



/**
 * @brief Função que executa query 1 se o argumento for um id de um driver e escreve num ficheiro txt a resposta à query 1 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) dos drivers 
 * @param id inteiro que será o id (drivers.csv)
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q1driver (DRIVERS_HT* lista, int id, int num){
    Driver d = q1d(lista,id);

    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);

    FILE *out_file = fopen(file_name, "w");

    if(d==NULL || strcmp(getDriverAccountStatus(d),"INACTIVE")==0){
        fprintf(out_file,"");
    }

    else{
        fprintf(out_file, "%s;%c;%d;%.3lf;%d;%.3lf\n", getDriverName(d), getDriverGender(d), idade(getBirthDay(d)), (getScore_d(d)/getn_viagensD(d)), getn_viagensD(d), getTotal_auferido(d));
    }
    

    fclose(out_file);
}


/**
 * @brief Função que executa query 2 e escreve num ficheiro txt a resposta à query 2 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os drivers no ficheiro de output.
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q2 (DRIVERS_HT* lista, int N, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    
    int i = 0;

    GList* list = sort_maior_avaliacao_media(lista); 
    
    
    while (i<N) {
        
        Driver d = (Driver) list->data;


        fprintf(out_file, "%012d;%s;%.3lf\n", getID(d), getDriverName(d),(getScore_d(d)/getn_viagensD(d)));
        list = list->next;
        i++;
    }
    g_list_free(list);
    fclose(out_file);
}


/**
 * @brief Função que executa query 3 e escreve num ficheiro txt a resposta à query 3 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) dos users
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os users no ficheiro de output.
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q3 (USER_HT* lista, int N, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    
    int i = 0;

    GList* list = sort__dist_t(lista); 
    
    
    while (i<N) {
        
        User u = (User) list->data;
        fprintf(out_file, "%s;%s;%d\n", getUsername(u), getUserXName(u),getDist_t(u));
        list = list->next;
        i++;
    }
    g_list_free(list);
    fclose(out_file);

}



/**
 * @brief Função que executa query 4 e escreve num ficheiro txt a resposta à query 4 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers 
 * @param cidade string que será a cidade (rides.csv)
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q4 (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade,int num){

    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);

    FILE *out_file = fopen(file_name, "w");

    double preco = preco_medio(lista,lista2,cidade);

    if (preco == 0.0){
        fprintf(out_file,"");
    }

    else{
        fprintf(out_file, "%.3lf", preco);
    }
    

    fclose(out_file);
}

/**
 * @brief Função que executa query 5 e escreve num ficheiro txt a resposta à query 5 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers 
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q5 (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2, int num){

    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);

    FILE *out_file = fopen(file_name, "w");

    double preco = preco_medio_entre_datas(lista,lista2,data1,data2);

    if (preco == 0.0){
        fprintf(out_file,"");
    }

    else{
        fprintf(out_file, "%.3lf", preco);
    }

    fclose(out_file);
}


/**
 * @brief Função que executa query 6 e escreve num ficheiro txt a resposta à query 6 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) das rides
 * @param cidade string que será a cidade (rides.csv)
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q6 (RIDES_HT* lista, char* cidade ,char* data1, char* data2, int num){

    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);

    FILE *out_file = fopen(file_name, "w");

    double dist = distancia_medio(lista,cidade,data1,data2);

    if (dist == 0){
        fprintf(out_file,"");
    }

    else{
        fprintf(out_file, "%.3lf", dist);
    }

    fclose(out_file);
}


/**
 * @brief Função que executa query 7 caso o input dado não tenha nenhum resultado
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param N   Número de vezes que o loop irá iterar e escrever uma linha vazia no ficheiro de output.
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q7_vazia (DRIVERS_HT* lista, int N, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    
    int i = 0;
    
    fprintf(out_file, "");
    
    /*
    while (i<N-1) {
        
        fprintf(out_file, "\n");
        
        i++;
    }*/
    fclose(out_file);
}


/**
 * @brief Função que executa query 7 e escreve num ficheiro txt a resposta à query 7 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os drivers no ficheiro de output.
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q7 (DRIVERS_HT* lista, int N, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    
    int i = 0;

    GList* list = avaliacao_cidade(lista); 
    
    
    while (i<N) {
        
        Driver d = (Driver) list->data;
     
        fprintf(out_file, "%012d;%s;%.3lf\n", getID(d), getDriverName(d),((double)getAvaliacao_cidade(d)/getViagens_cidade(d)));
        list = list->next;
        i++;
    }
    g_list_free(list);
    fclose(out_file);
}



/**
 * @brief Função que executa query 8 e escreve num ficheiro txt a resposta à query 8 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers
 * @param g género dado como argumento
 * @param anos número de anos dado como argumento que uma conta deve ter 
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q8 (RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3 ,char g, int anos, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    
   

    GList* list = sort_conta_mais_antiga(lista,lista2,lista3,g,anos); 
  
    if(list == NULL){
       fprintf(out_file, "");
    }
    
    while (list) {
        
        Rides r = (Rides) list->data;
        Driver d = q1d(lista2,getdriver(r));
        User u = q1u(lista3,getUser(r));

        
        fprintf(out_file, "%012d;%s;%s;%s\n", getID(d), getDriverName(d), getUsername(u), getUserXName(u));
        list = list->next;
    }   
    fclose(out_file);
    g_list_free(list);
}


/**
 * @brief Função que executa query 9 e escreve num ficheiro txt a resposta à query 9 pedida no ficheiro de input
 *
 * @param lista catálogo (hashtable) das rides
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado
 * @param num numero da linha do ficheiro input que está a ser lida
 * 
 */
void q9 (RIDES_HT* lista, char* data1, char* data2, int num){
    char file_name[100];
    snprintf(file_name,100,"Resultados/command%d_output.txt",num);
    FILE *out_file = fopen(file_name, "w");
    

    GList* list = sort_menor_dist(lista,data1,data2); 
  
    char* date_string;
    date_string = (char*) malloc(sizeof(char) * 20);    
    
    if(list == NULL){
       fprintf(out_file, "");
    }

    while (list) {
        
        Rides r = (Rides) list->data;

        date_string = convert_date_to_string(getDate(r));
        
        fprintf(out_file, "%012d;%s;%d;%s;%.3lf\n", getIDRides(r), date_string, getDistance(r), getCity(r), getTip(r));
        list = list->next;

        
    }

    
    fclose(out_file);
    free(date_string);
    g_list_free(list);
}
