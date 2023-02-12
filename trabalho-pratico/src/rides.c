/**
 * @file rides.c
 *
 * Este ficheiro contém a struct das rides, a função que cria uma ride válida e a hashtabel com as rides válidas
*/


#include "../include/rides.h" 
#define FREE(algo) if (algo) free(algo)



/*id;date;driver;user;city;distance;score_user;score_driver;tip;comment*/


/**
 * @brief Type usado para definir uma ride
 */
struct rides {

  int id;

  Date date;

  int driver;

  char* user;

  char* city;

  int distance;

  double score_user;

  double score_driver;

  double tip;

  char* comment;

  Date account_creation_driver;

  Date account_creation_user;

};

/**
 * @brief definição de uma hashtable para as rides
 */
struct rides_ht{
  GHashTable* rides_hash;
};


/**
 * @brief         Define o ID de uma #Ride
 *
 * @param rides   A #Ride dada
 * @param iD      O ID da #Ride
 *
*/
void setIDRides (Rides rides, int iD) {
  rides -> id = iD;
}


/**
 * @brief        Obtém o ID de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       O ID de uma #Ride
 */
int getIDRides (Rides rides) {
  return (rides -> id);
}


/**
 * @brief        Define a data de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param date   A data da #Ride
 *
*/
void setDate (Rides rides, Date date) {
    rides -> date = copyDate (date);
}


/**
 * @brief        Obtém a data de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       A data da #Ride
 */
Date getDate (Rides rides) {
  return copyDate(rides -> date);
}


/**
 * @brief           Define o driver de uma #Ride
 *
 * @param rides     A #Ride dada
 * @param iD_driver O ID de um driver
 *
*/
void setdriver (Rides rides, int iD_driver) {
  rides -> driver = iD_driver;
}


/**
 * @brief        Obtém o condutor de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       O condutor da #Ride
 */
int getdriver (Rides rides){
  return (rides -> driver);
}


/**
 * @brief        Define o utilizador de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param usr    O utilizador da #Ride
 *
*/
void setUser (Rides rides, char* usr) {
  rides -> user = strdup (usr);
}


/**
 * @brief        Obtém o utilizador de uma #Ride
 *
 * @param rides  A #Ride dado
 *
 * @return       O utilizador da #Ride
 */
char* getUser (Rides rides) {
  return strdup(rides -> user);
}


/**
 * @brief        Define a cidade de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param ct     A cidade da #Ride
 *
*/
void setCity (Rides rides, char* ct) {
  rides -> city = strdup (ct);
}


/**
 * @brief        Obtém a cidade de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       A cidade da #Ride
 */
char* getCity (Rides rides) {
  return (rides -> city);
}


/**
 * @brief      Função auxiliar que verifica se a distẫncia é válida
 *
 * @param dst  A distância dada
 *
 * @return     1, caso a 'dst' seja maior que 0, 0 caso contrário
 *
*/
int validDistance (int dst) {
  if (dst > 0) return 1;
  else return 0;
}


/**
 * @brief        Define distância de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param dst    A distância da #Ride
 *
*/
void setDistance (Rides rides, int dst) {
  if (validDistance(dst)) rides -> distance = dst;
}


/**
 * @brief        Obtém a distância de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       A distância da #Ride
 */
int getDistance (Rides rides) {
  return (rides -> distance);
}


/**
 * @brief    Função auxiliar que verifica se um inteiro pertence a uma certa lista de tamanho N de inteiros
 *
 * @param x  inteiro que se quer saber se pertence á lista
 * @param v  lista de inteiros
 * @param N  tamanho da lista
 *
 * @return   1, caso x pertença à lista, 0 caso contrário
 *
*/
int elem (int x, int v[], int N) {
  int i;
   for (i=0; i<N; i++) {
     if (x == v[i]) return 1;
     else i = i+1;
   }
  return 0;
}


/**
 * @brief        Define a pontuação de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param scr    A pontuação da #Ride
 *
*/
void setUserScore (Rides rides, int scr) {
  rides -> score_user = scr;
}


/**
 * @brief        Obtém a pontuação de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       A pontuação da #Ride
 */
int getUserScore (Rides rides) {
  return (rides -> score_user);
}


/**
 * @brief         Define a pontução do driver de uma #Ride
 *
 * @param rides   A #Ride dada
 * @param scr     A pontuação do driver da #Ride
 *
*/
void setDriverScore (Rides rides, int scr) {
  rides -> score_driver = scr;
}


/**
 * @brief        Obtém a pontuação do driver da #Ride
 *
 * @param rides  A #Ride dado
 *
 * @return       A pontuação do driver da #Ride
 */
double getDriverScore (Rides rides) {
  return (rides -> score_driver);
}


/**
 * @brief        Define a tip de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param tp     A tip da #Ride
 *
*/
void setTip (Rides rides, double tp) {
  rides -> tip = tp;
}


/**
 * @brief        Obtém a tip de uma #Ride
 *
 * @param rides  A #Ride dado
 *
 * @return       A tip da #Ride
 */
double getTip (Rides rides) {
  return (rides -> tip);
}


/**
 * @brief        Define o comentário de uma #Ride
 *
 * @param rides  A #Ride dada
 * @param cmnt   O comentário da #Ride
 *
*/
void setComment (Rides rides, char* cmnt) {
  rides -> comment = strdup(cmnt);
}


/**
 * @brief        Obtém o comentário de uma #Ride
 *
 * @param rides  A #Ride dada
 *
 * @return       O comentário da #Ride
 */
char* getComment (Rides rides) {
  return rides -> comment == NULL ? NULL : strdup(rides -> comment);
}

/**
 * @brief        Define a data de criação da conta de um #Driver
 *
 * @param rides  A #Ride dada
 * @param date   A #Date de criação 
 *
*/
void setAccountD (Rides rides, Date date) {
   rides -> account_creation_driver = (date);
}

/**
 * @brief        Obtém a data de criação da conta de um #Driver
 *
 * @param rides  A #Ride dada
 * 
 * @return       A #Date de criação
 *
*/
Date getAccountD (Rides rides) {
   return copyDate(rides -> account_creation_driver);
}

/**
 * @brief        Define a data de criação da conta de um #User
 *
 * @param rides  A #Ride dada
 * @param date   A #Date de criação 
 *
*/
void setAccountU (Rides rides, Date date) {
   rides -> account_creation_user =  (date);
}

/**
 * @brief        Obtém a data de criação da conta de um #User
 *
 * @param rides  A #Ride dada
 * 
 * @return       A #Date de criação
 *
*/
Date getAccountU (Rides rides) {
   return copyDate(rides -> account_creation_user);
}

/**
 * @brief         Função que verifica se uma string corresponde a um número decimal
 *
 * @param buffer  string dada
 *
 * @return        valor (val), se o resto for igual a 0
 *                (-1), caso contrário
 */
double validDecimal (char *buffer)
{
  char *resto;

  double val = strtod(buffer, &resto);

  if ((*resto) == 0)
    return val;
  else return -1;
}


/**
 * @brief        Liberta a memória ocupada por cada campo da Ride (user, city, comment) e, no fim, ao próprio r
 *
 * @param data   Pointer "data" associado a uma Ride
 *
*/
void delete_ride(void* data){
  Rides r = (Rides) data;
  FREE(r-> user);
  FREE(r->city);
  FREE(r->comment);
  FREE(r);
}


/**
 * @brief       Verifica se uma dada #Ride tem todos os parametros válidos
 *
 * @param line  string com os paremetros de uma #Ride
 *
 * @return      A #Ride caso todos os parametros sejam válidos e NULL caso contrário
 */
Rides build_rides (char *line){
  Rides rd = malloc(sizeof(struct rides));
  memset(rd,0,sizeof(struct rides));
  int i = 0;
  char *buffer;

  while ((buffer = strsep(&line, ";\n")) != NULL) {
    // int aux;
    switch (i++) {
      case 0:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        rd->id = atoi(buffer);
        break;
      case 1:
        rd->date = valid_date(buffer);
        if (rd->date == NULL) {delete_ride(rd); return NULL;}
        break;
      case 2:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        rd->driver = atoi(buffer);
        break;
      case 3:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        rd->user = strdup(buffer);
        break;
      case 4:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        rd->city = strdup(buffer);
        break;
      case 5:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        if(atoi(buffer)<0) {delete_ride(rd); return NULL;}
        if(strstr(buffer,".")) {delete_ride(rd); return NULL;}
        rd->distance = atoi(buffer);
        break;
      case 6:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        double s_u = validDecimal(buffer);
        if(s_u<0) {delete_ride(rd); return NULL;}
        rd->score_user = s_u;
        break;
      case 7:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        double s_d = validDecimal(buffer);
        if(s_d<0) {delete_ride(rd); return NULL;}
        rd->score_driver = s_d;
        break;
      case 8:
        if (strlen(buffer)==0) {delete_ride(rd); return NULL;}
        double t = validDecimal(buffer);
        if(t<0) {delete_ride(rd); return NULL;}
        rd->tip = t;
        break;
      case 9:
        if (strlen(buffer)==0) rd->comment = NULL;
        else rd->comment = strdup(buffer);
        break;
    }
  }
  rd->account_creation_driver = NULL;
  rd->account_creation_user = NULL;
  return rd;
}



/**
 * @brief        Função auxiliar que atualiza algumas variáveis da strust dos drivers e dos users
 *
 * @param lista  catálogo (hashtable) dos users
 * @param lista2 catálogo (hashtable) dos drivers
 * @param r      ride
 *
*/
void set (USER_HT *lista, DRIVERS_HT *lista2, Rides r){
      
      User u = q1u(lista, r->user);
      Driver d = q1d(lista2,r->driver);
      
      
      setScore_u(u,(getScore_u(u)+getUserScore(r)));
      setn_viagensU(u,getn_viagensU(u)+1);
      setTotal_gasto(u, getTotal_gasto(u)+preco_class(lista2,getID(d),getdriver(r))+getTip(r));
      setDist_t(u,getDistance(r)+getDist_t(u));

      if(menor(getV_recenteU(u),r->date) == 1){
        setV_recenteU(u,r->date);
      }
      
      setSore_d(d,getScore_d(d)+getDriverScore(r));
      setn_viagensD(d, getn_viagensD(d)+1);
      setTotal_auferido(d,getTotal_auferido(d)+preco_class(lista2,getdriver(r),getDistance(r))+getTip(r));

      setAccountD(r,getDriverAccountCreation(d));
      setAccountU(r,getUserAccountCreation(u));
      
      
      if(menor(getV_recente(d),r->date) == 1){
        setV_recente(d,r->date);
      }

}



/**
 * @brief função que cria um catálogo (hashtable) com todas as linhas válidas do ficheiro rides.csv
 *
 * @param ficheiro_entrada path para o ficheiro que se vai abrir para ser lido
 * @param lista            catálogo (hashtable) dos users
 * @param lista2           catálogo (hashtable) dos drivers
 *
 * @return hashtable com todas as rides válidas
 */
RIDES_HT* create_RidesHt (char* ficheiro_entrada, USER_HT* lista, DRIVERS_HT* lista2){
  FILE *f;


  f = fopen(ficheiro_entrada, "r");

  if (!f){
    perror("Erro");
    return NULL;
  }

  RIDES_HT* new = malloc (sizeof(struct rides_ht));
  new->rides_hash = g_hash_table_new_full(g_int_hash, g_int_equal,NULL,delete_ride);

  char line[1000];
  int buffer_size = 1000;

  while(fgets(line, buffer_size, f)) {

      Rides rd = build_rides(strdup(line));   // passas strdup para salvaguardar a linha original
      if (rd != NULL){
          
        g_hash_table_insert(new->rides_hash, &rd->id, rd);
        set(lista,lista2,rd);
      }      
}

  fclose(f);

  return new;
}


/**
 * @brief         Funcão auxiliar liberta da memória a hashtable das rides
 *
 * @param lista   catálogo (hashtable) das rides
 */
void delete_rides_hash (RIDES_HT* lista){
  g_hash_table_destroy(lista->rides_hash);
  FREE(lista);
}


/**
 * @brief        Função auxiliar que calcula Preço médio numa determinada cidade
 * 
 * @param lista  catálogo (hashtable) das rides
 * @param lista2 catálogo (hashtable) dos drivers
 * @param cidade cidade dada
 *
 * @return       preço médio das viagens numa certa cidade
 */
double preco_medio (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade){
    GHashTableIter iter;
    gpointer key, value;

    
    double p = 0;
    int N=0;

    g_hash_table_iter_init (&iter,lista->rides_hash);
    while (g_hash_table_iter_next (&iter, &key, &value)){
      Rides r = (Rides) value;
      if(strcmp(r->city,cidade)==0){
        double pc = preco_class(lista2,getdriver(r),getDistance(r));
        p += pc;
        N++;
      }
    }

    if (p==0 && N ==0){
      return 0.0;
    }
    else{
      return (p/N);
    }
}


/**
 * @brief         Função auxiliar que calcula Preço médio das viagens num dado intervalo de tempo, sendo esse intervalo representado por <data A> e <data B>.
 *
 * @param lista   catálogo (hashtable) das rides
 * @param lista2  catálogo (hashtable) das drivers
 * @param data1   data minima
 * @param dat2    data máxima
 *
 * @return        preço médio das viagens num dado intrevalo de tempo
 */
double preco_medio_entre_datas (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2){
    GHashTableIter iter;
    gpointer key, value;


    Date date1 = valid_date (data1);
    Date date2 = valid_date (data2);
   
    double p = 0;
    int N=0;

    g_hash_table_iter_init (&iter,lista->rides_hash);
    while (g_hash_table_iter_next (&iter, &key, &value)){
      Rides r = (Rides) value;
      if(entre_datas(r->date,date1,date2)){
        p += preco_class(lista2,getdriver(r),getDistance(r));
        N++;
      }
    }
    
    FREE(date1);
    FREE(date2);

    if (p==0 && N ==0){
      return 0.0;
    }
    else{
      return (p/N);
    }
}

/**
 * @brief         Função auxiliar que calcula Preço médio das viagens numa certa cidade num dado intervalo de tempo, sendo esse intervalo representado por <data A> e <data B>.
 *
 * @param lista   catálogo (hashtable) das rides
 * @param lista2  catálogo (hashtable) das drivers
 * @param cidade  cidade dada
 * @param data1   data minima
 * @param dat2    data máxima
 *
 * @return        preço médio das viagens numa certa cidade num dado intrevalo de tempo
 */
double distancia_medio (RIDES_HT* lista, char* cidade ,char* data1, char* data2){
    GHashTableIter iter;
    gpointer key, value;

    Date date1 = valid_date (data1);
    Date date2 = valid_date (data2);
    int dist = 0;
    int N = 0;


    g_hash_table_iter_init (&iter,lista->rides_hash);
    while (g_hash_table_iter_next (&iter, &key, &value)){
      Rides r = (Rides) value;
      if(strcmp(r->city,cidade)==0 && entre_datas_incluindo(r->date,date1,date2)){
        dist += getDistance(r);
        N++;
      }
    }

    FREE(date1);
    FREE(date2);

    if (dist == 0 && N==0){
      return 0;
    }
    else{
        return ((double)dist/N);
    }
}

/**
 * @brief         Função auxiliar que atualiza as variáveis avaliação_cidade e a viagens_cidade da struct dos drivers
 *
 * @param lista   catálogo (hashtable) das rides
 * @param lista2  catálogo (hashtable) das drivers
 * @param cidade  cidade dada
 * 
 */
int avaliacao_t_cidade (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade){
    GHashTableIter iter;
    gpointer key, value;

    int f = 0;
    

    g_hash_table_iter_init (&iter,lista->rides_hash);
    while (g_hash_table_iter_next (&iter, &key, &value)){
      Rides r = (Rides) value;
      Driver d = q1d(lista2,getdriver(r));

      if(strcmp(r->city,cidade)==0){
        setAvaliacao_cidade(d,getDriverScore(r)+getAvaliacao_cidade(d));
        setViagens_cidade(d,getViagens_cidade(d)+1);
        f=1;
      }
    }

    if (f==0){
      return 0;
    }
    else{
      return 1;
    }
}


/**
 * @brief         Função auxiliar que cria uma lista ligada com todas as rides onde 
 *                o utilizador e o condutor têm o gênero passado como argumento e x ou 
 *                mais anos de conta 
 *
 * @param lista   catálogo (hashtable) das rides
 * @param lista2  catálogo (hashtable) das drivers
 * @param lista3  catálogo (hashtable) dos users
 * @param g       gênero
 * @param anos    anos de conta
 * 
 * @return        A lista ligada com todas as rides onde o utilizador e o condutor têm 
 *                o gênero passado como argumento e x ou mais anos de conta 
 */
GList* list_rides_8 (RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3, char g, int anos){
  GHashTableIter iter;
  gpointer key, value;
  
  GList* list = NULL;


  g_hash_table_iter_init (&iter,lista->rides_hash);
  while (g_hash_table_iter_next (&iter, &key, &value)){
    Rides r = (Rides) value;
    Driver d = q1d(lista2,getdriver(r));
    User u = q1u(lista3,getUser(r));

    int i_u = idade(getAccountU(r));
    int i_d = idade(getAccountD(r));

    if(getUserGender(u)==g && getDriverGender(d)==g && i_u >= anos && i_d >= anos){
      list = g_list_append(list,r);
    }
  }

  return list;
}

/**

*@brief   Função auxiliar que compara duas rides com base nas datas de criação
*
*@param a Um pointer para a primeira ride
*
*@param b Um pointer para a segunda ride
*
*@return Se o output for positivo, isso significa que o objeto "b" tem uma data de criação de conta mais recente, seja do driver ou do user
*        Se o output for zero, significa que ambos os objetos têm as mesmas datas de criação de conta tanto para o driver como para o user
*        Se o output for negativo, significa que o objeto "a" tem uma data de criação de conta mais recente, seja do driver ou do user
*        Se o output for a subtração do identificador do objeto "b" pelo identificador do objeto "a", significa que ambos os objetos têm as mesmas 
         datas de criação de conta tanto para o driver como para o user, e a ordem relativa entre eles é determinada pelos ids

*/
gint conta_mais_antiga (gconstpointer a, gconstpointer b) {
  Rides r_a = (Rides) a;
  Rides r_b = (Rides) b;
  
  if(datas_iguais(r_a->account_creation_driver,r_b->account_creation_driver) && datas_iguais(r_a->account_creation_user,r_b->account_creation_user)){
    return (r_b->id-r_a->id);
  }
  
  if(datas_iguais(r_a->account_creation_driver,r_b->account_creation_driver)){
    return compareDates(r_b->account_creation_user,r_a->account_creation_user);
  }

  

  return compareDates(r_b->account_creation_driver,r_a->account_creation_driver);
}

/**
 * @brief         Funcão auxiliar que transforma a hashtable numa lista ligada e ordena-a por ordem descrescente da idade da conta
 *
 * @param lista   catálogo (hashtable) das rides
 * @param lista2  catálogo (hashtable) das drivers
 * @param lista3  catálogo (hashtable) dos users
 * @param g       gênero
 * @param anos    anos de conta
 * 
 * @return       A lista ligada ordenada pela idade da conta
 */
GList* sort_conta_mais_antiga(RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3, char g, int anos){
  
  GList* values = list_rides_8(lista,lista2,lista3,g,anos);
  
  if (values == NULL) {
    //printf("erro na conta_mais_antiga\n");
    return NULL;
  }

  values = g_list_sort(values, conta_mais_antiga);
  
  return values;
}

/**
 * @brief        Função auxiliar que cria uma lista ligada com todas as rides onde 
 *               a tip é maior que 0 e a data da ride está entre um certo intervalo 
 *               de tempo
 *
 * @param lista  catálogo (hashtable) das rides
 * @param date1  uma #Date dada
 * @param date2  uma #Date dada

 * 
 * @return       A lista ligada com todas as rides onde a tip é maior que 0 e a data da
 *               ride está entre um certo intervalo de tempo
 */
GList* list_rides_9 (RIDES_HT* lista, char* date1, char* date2){
  GHashTableIter iter;
  gpointer key, value;
  
  GList* list = NULL;

  Date data1 = valid_date(date1);
  Date data2 = valid_date(date2);

  int f = 0;

  g_hash_table_iter_init (&iter,lista->rides_hash);
  while (g_hash_table_iter_next (&iter, &key, &value)){
    Rides r = (Rides) value;

    if((r->tip)>0 && (entre_datas_incluindo(r->date,data1,data2)==1)) {
      list = g_list_append(list,r);
      f = 1;
    }
  }

  FREE(data1);
  FREE(data2);


  if(f==0){
    return NULL;
  }
  else{
    return list;
  }
}

/**

*@brief   Função auxiliar que compara duas rides com base nas distâncias percorridas
*
*@param a Um pointer para a primeira ride
*
*@param b Um pointer para a segunda ride
*
*@return Se o output for positivo, isso significa que o objeto "b" é posterior ao objeto "a", seja pela distância ou pela data
*        Se o output for zero, significa que ambos os objetos são iguais tanto pela distância quanto pela data
*        Se o output for negativo, significa que o objeto "a" é posterior ao objeto "b", seja pela distância ou pela data
*        Se o output for a subtração do identificador do objeto "b" pelo identificador do objeto "a", significa que ambos os 
         objetos têm a mesma distância e a mesma data, e que a ordem relativa entre eles é determinada pelos ids
*/
gint compara_distancia(gconstpointer a, gconstpointer b) {
  Rides r_a = (Rides) a;
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

/**
 * @brief        Funcão auxiliar que transforma a hashtable numa lista ligada e ordena-a por ordem descrescente da distância percorrida
 *
 * @param table  catálogo (hashtable) das rides
 * @param date1  uma #Date dada
 * @param date2  uma #Date dada

 * 
 * @return       A lista ligada ordenada pela distância percorrida
 */
GList* sort_menor_dist (RIDES_HT* table, char* data1, char* data2) {
  
  GList* values = list_rides_9(table,data1,data2);
  
  if (values == NULL) {
    //printf("erro na sort_menor_dist ");
    return NULL;
  }

  values = g_list_sort(values, compara_distancia);

  return values;
}