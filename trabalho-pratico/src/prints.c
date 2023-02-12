/**
 * @file prints.c
 * 
 * Este ficheiro é responsável pela interação no terminal
 * Lê comandos, aplica a query e dá print aos outputs no terminal
*/
#include "../include/prints.h"



/**
 * @brief Função que dá print do menu no terminal
 */
void printMenu() {
    printf(
    "\033[1;36m"
    "\n"
    "------------------------------------------------------------MENU-------------------------------------------------------------------------\n"
    "\033[1;30m"
    "| "
    "\033[0m"
    " Escolha a query que pretende executar, escrevendo o número seguido de um espaço e o/os argumentos necessários                        |\n"                         
    "\033[1;30m"
    "|                                                                                                                                       |\n"
    "\033[0m"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 0|    Escreva 0 para sair                                                                                                             |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 1| -> Para executar a query 1, escreva 1 e o respetivo argumento (1 username ou 1 id)                                                 |\n"
    "|       Lista o resumo de um perfil registado no serviço através do seu id caso seja um driver e um username caso seja um user          |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 2| -> Para executar a query 2, escreva 2 e o respetivo argumento (2 N)                                                                |\n"
    "|       Lista os N condutores com maior avaliação média                                                                                 |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 3| -> Para executar a query 3, escreva 3 e o respetivo argumento (3 N)                                                                |\n"
    "|       Lista os N utilizadores com maior distância viajada                                                                             |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 4| -> Para executar a query 4, escreva 4 e o respetivo argumento (4 cidade)                                                           |\n"
    "|       Preço médio das viagens (sem considerar gorjetas) numa determinada cidade                                                       |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "| 5| -> Para executar a query 5, escreva 5 e o respetivo argumento (5 dataA dataB)                                                      |\n"
    "|       Preço médio das viagens (sem considerar gorjetas) num dado intervalo de tempo                                                   |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "\033[0m"
    "| 6| -> Para executar a query 6, escreva 6 e o respetivo argumento (6 cidade dataA dataB)                                               |\n"
    "|       Distância média percorrida, numa determinada cidade, num dado intervalo de tempo                                                |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "\033[0m"
    "| 7| -> Para executar a query 7, escreva 7 e o respetivo argumento (7 N cidade)                                                         |\n"
    "|       Top N condutores numa determinada cidade                                                                                        |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "\033[0m"
    "| 8| -> Para executar a query 8, escreva 8 e o respetivo argumento (8 género anos_de_conta)                                             |\n"
    "|       Lista as viagens nas quais o utilizador e o condutor são do género passado como argumento e têm conta com X ou mais anos        |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "\033[0m"
    "| 9| -> Para executar a query 9, escreva 9 e o respetivo argumento (9 dataA dataB)                                                      |\n"
    "|       Lista as viagens nas quais o passageiro deu gorjeta num dado intervalo de tempo                                                 |\n"
    "|"
    "\033[1;36m"
    "---------------------------------------------------------------------------------------------------------------------------------------"
    "\033[0m"
    "|\n"
    "\033[1;36m"
    "\033[0m"
    "\n"
    "-> "
    );
}

/**
 * @brief Função que executa query 1 se o argumento for um username de um user e dá print no terminal ao resultado da query 1 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) dos users 
 * @param username string que será o username (users.csv)
 * 
 */
void print_q1users (USER_HT* lista, char* username){
    User u = q1u(lista, username);
    
    if (u == NULL || strcmp(getUserAccountStatus(u),"INACTIVE")==0){
        printf("\n");
    }
    else{
        printf("%s;%c;%d;%.3lf;%d;%.3lf\n", getUserXName(u), getUserGender(u), idade(getBirthDate(u)), (getScore_u(u)/getn_viagensU(u)), getn_viagensU(u), getTotal_gasto(u));
    }

    
}

/**
 * @brief Função que executa query 1 se o argumento for um id de um driver e dá print no terminal ao resultado da query 1 pedida pelo utilizador
 * 
 * @param lista catálogo (hashtable) dos drivers 
 * @param id inteiro que será o id (drivers.csv)
 * 
 */
void print_q1driver (DRIVERS_HT* lista, int id){
    Driver d = q1d(lista,id);
    
    if (d == NULL || strcmp(getDriverAccountStatus(d),"INACTIVE")==0){
        printf("\n");
    }
    else{
        printf("%s;%c;%d;%.3lf;%d;%.3lf\n", getDriverName(d), getDriverGender(d), idade(getBirthDay(d)), (getScore_d(d)/getn_viagensD(d)), getn_viagensD(d), getTotal_auferido(d));
    }

    
}

/**
 * @brief Função que executa query 2 e dá print no terminal ao resultado da query 2 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os drivers no terminal.
 * 
 */
void print_q2 (DRIVERS_HT* lista, int N){
    int i = 0;

    GList* list = sort_maior_avaliacao_media(lista); 
    
    while (i<N) {
        
        Driver d = (Driver) list->data;
        printf("%d;%s;%.3lf\n", getID(d), getDriverName(d),(getScore_d(d)/getn_viagensD(d)));
        list = list->next;
        i++;
    
    }
}   



/**
 * @brief Função que executa query 3 e dá print no terminal ao resultado da query 3 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) dos users
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os users no terminal.
 * 
 */
void print_q3 (USER_HT* lista, int N){
    int i = 0;

    GList* list = sort__dist_t(lista); 
    
    while (i<N) {
        
        User u = (User) list->data;
        printf("%s;%s;%d\n", getUsername(u), getUserXName(u),getDist_t(u));
        list = list->next;
        i++;    
    }
}


/**
 * @brief Função que executa query 4 e dá print no terminal ao resultado da query 4 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers 
 * @param cidade string que será a cidade (rides.csv)
 * 
 */
void print_q4 (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade){

    double preco = preco_medio(lista,lista2,cidade);

    if (preco == 0.0){
        printf("\n");
    }

    else{
        printf("%.3lf\n", preco);
    }
    
}

/**
 * @brief Função que executa query 5 e dá print no terminal ao resultado da query 5 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers 
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado

 * 
 */
void print_q5 (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2){
    
    double preco = preco_medio_entre_datas(lista,lista2,data1,data2);

    if (preco == 0.0){
        printf("\n");
    }

    else{
        printf("%.3lf\n", preco);
    }
    
}


/**
 * @brief Função que executa query 6 e dá print no terminal ao resultado da query 6 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) das rides
 * @param cidade string que será a cidade (rides.csv)
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado
 * 
 */
void print_q6 (RIDES_HT* lista, char* cidade ,char* data1, char* data2){
    
    double dist = distancia_medio(lista,cidade,data1,data2);

    if (dist == 0){
        printf("\n");
    }

    else{
        printf("%.3lf\n", dist);
    }
    
}


/**
 * @brief Função que executa query 7 e dá print no terminal ao resultado da query 7 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param N   Número de vezes que o loop irá iterar e escrever informações sobre os drivers no terminal.
 * 
 */
void print_q7 (DRIVERS_HT* lista, int N){
    int i = 0;

    GList* list = avaliacao_cidade(lista); 

    
    while (i<N) {
        
        Driver d = (Driver) list->data;
        printf("%d;%s;%.3f\n", getID(d), getDriverName(d),((double)getAvaliacao_cidade(d)/getViagens_cidade(d)));
        list = list->next;
        i++;    
    }
}


/**
 * @brief Função que executa query 8 e dá print no terminal ao resultado da query 8 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers
 * @param g género dado como argumento
 * @param anos número de anos dado como argumento que uma conta deve ter 
 * 
 */
void print_q8 (RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3, char g, int anos){

    GList* list = sort_conta_mais_antiga(lista,lista2,lista3,g,anos); 

    if(list == NULL){
       printf("");
    }
    
    while (list) {
        
        Rides r = (Rides) list->data;
        Driver d = q1d(lista2,getdriver(r));
        User u = q1u(lista3,getUser(r));

        
        printf("%d;%s;%s;%s\n", getID(d), getDriverName(d), getUsername(u), getUserXName(u));
        list = list->next;
    }     
}

/**
 * @brief Função que executa query 9 e dá print no terminal ao resultado da query 9 pedida pelo utilizador
 *
 * @param lista catálogo (hashtable) das rides
 * @param data1 limite inferior do intervalo de tempo dado
 * @param data2 limite superior do intervalo de tempo dado
 * 
 */
void print_q9 (RIDES_HT* lista, char* data1, char* data2){
    GList* list = sort_menor_dist(lista,data1,data2); 
  
    char* date_string;
    
    if(list == NULL){
       printf("");
    }

    while (list) {
        
        Rides r = (Rides) list->data;

        date_string = convert_date_to_string(getDate(r));

        printf("%d;%s;%d;%s;%.3f\n", getIDRides(r), date_string,getDistance(r), getCity(r), getTip(r));
        list = list->next;
        date_string = NULL;
    }
}