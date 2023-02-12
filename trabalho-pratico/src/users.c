/**
 * @file users.c
 *
 * Este ficheiro contém a struct dos users, a função que cria um user válido e a hashtabel com os users válidos
*/


#include "../include/users.h"
#define FREE(algo) if (algo) free(algo)

/* username;name;gender;birth_date;account_creation;pay_method;account_status */

/**
 * @brief Type usado para definir um user
 */
struct user {
  char* username;

  char* name;

  char gender;

  Date birth_date;

  Date account_creation;

  char* pay_method;

  char* account_status;

  double total_gasto;

  double score_u;

  int n_viagensU;

  int dist_t;

  Date v_recenteU;
};

/**
 * @brief
 */
struct user_ht{
  GHashTable* users_hash;
};



/**
 * @brief           Define o username do #User
 *
 * @param user      O #User dado
 * @param usr       O username do #User
 *
*/
void setUsername (User user, char *usr) {
  user -> username = strdup (usr);
}


/**
 * @brief       Obtém o username de um #User
 *
 * @param user  O #User dado
 *
 * @return      O username do #User
 */
char* getUsername (User user) {
  return strdup(user -> username);  // strdup para fazer encapsulamento
}


/**
 * @brief           Define o nome do #User
 *
 * @param user      O #User dado
 * @param nm        O nome do #User
 *
*/
void setUserXName (User user, char *nm) {
  user -> name = strdup (nm); // strdup para fazer encapsulamento
}


/**
 * @brief       Obtém o nome de um #User
 *
 * @param user  O #User dado
 *
 * @return      O nome do #User
 */
char* getUserXName (User user) {
  return strdup(user -> name);  // encapsulamento x2
}


/**
 * @brief           Função auxiliar que verifica se o género é válido
 *
 * @param gndr      O género dado
 *
 * @return          1, caso o 'gndr' seja "M" ou "F", 0 caso contrário
 *
*/
int validUserGender (char gndr) {
  if ((gndr == 'M') || (gndr == 'F')) return 1;
  else return 0;
}


/**
 * @brief           Define o género de um #User
 *
 * @param user      O #User dado
 * @param gndr      O género do #User
 *
*/
void setUserGender (User user, char gndr) {
  if (validUserGender(gndr)) user->gender = gndr;
}


/**
 * @brief       Obtém o género de um #User
 *
 * @param user  O #User dado
 *
 * @return      O género do #User
 */
char getUserGender (User user) {
  return user->gender;
}


/**
 * @brief           Define a data de nasimento de um #User
 *
 * @param user      O #User dado
 * @param date      A data de nascimento do #User
 *
*/
void setBirthDate (User user, Date date) {
    if (valid_date(date)) user -> birth_date = copyDate (date);
}


/**
 * @brief       Obtém a data de nascimento de um #User
 *
 * @param user  O #User dado
 *
 * @return      A data de nascimento do #User
 */
Date getBirthDate (User user) {
   return copyDate (user -> birth_date);
}


/**
 * @brief           Define a data em que a conta de um #User foi criada
 *
 * @param user      O #User dado
 * @param date      A data da criação da conta do #User
 *
*/
void setUserAccountCreation (User user, Date date) {
   user -> account_creation = copyDate (date);
}


/**
 * @brief       Obtém a data em que a conta de um #User foi criada
 *
 * @param user  O #User dado
 *
 * @return      A data de criação da conta do #User
 */
Date getUserAccountCreation (User user) {
   return copyDate (user -> account_creation);
}


/**
 * @brief           Função auxiliar com função de verificar se o método de pagamento é válido
 *
 * @param pm        O método de pagamento do #User
 *
 * @return          1 se o pm for "credit_card" ou "debit_card" ou "cash", 0 caso contrário
 *
*/
int validPayMethod (char *pm) {
  char pm1[] = "credit_card" , pm2[] = "debit_card" , pm3[] = "cash";
  if ((strcmp (pm, pm1)==0) || (strcmp (pm, pm2)==0) || (strcmp (pm,pm3)==0)) return 1;
  else return 0;
}


/**
 * @brief           Define o método de pagamento de um #User
 *
 * @param user      O #User dado
 * @param pm        O método de pagamento do #User
 *
*/
void setPayMethod (User user, char *pm) {
  if (validPayMethod (pm)) user->pay_method = strdup(pm);
}


/**
 * @brief       Obtém o método de pagamento de um #User
 *
 * @param user  O #User dado
 *
 * @return      O método de pagamento do #User
 */
char* getPayMethod (User user) {
  return strdup(user->pay_method);
}


/**
 * @brief           Função auxiliar com função de verificar se o account status é válido
 *
 * @param as        O account status do #User
 *
 * @return          1 se o as for "ACTIVE" ou"INACTIVE", 0 caso contrário
 *
*/
int validUserAccountStatus (char *as) {
  char as1[] = "ACTIVE" , as2[] = "INACTIVE";
  unsigned i;
  for (i=0; i <strlen(as); i++) {
    as[i] = toupper(as[i]);
  }

  if ((strcmp (as, as1)==0) || (strcmp (as, as2)==0)) return 1;
  else return 0;
}


/**
 * @brief           Define o estado da conta de um #User
 *
 * @param user      O #User dado
 * @param as        O estado da conta do #User
 *
*/
void setUserAccountStatus (User user, char *as) {
  if (validUserAccountStatus (as)) user->account_status = strdup(as);
}


/**
 * @brief       Obtém o estado da conta de um #User
 *
 * @param user  O #User dado
 *
 * @return      O estado da conta do #User
 */
char* getUserAccountStatus (User user) {
  return strdup(user->account_status);
}

/**
 * @brief           Define o total gasto de um dado #User
 *
 * @param user      O #User dado
 * @param t         Total gasto do #User
 *
*/
void setTotal_gasto (User user, double t) {
  user -> total_gasto = t;
}

/**
 * @brief       Obtém o total gasto de um dado #User
 *
 * @param user  O #User dado
 *
 * @return      O total gasto do #User
 */
double getTotal_gasto (User user) {
  return (user -> total_gasto);
}

/**
 * @brief        Define o score total do #User
 *
 * @param user   O #User dado
 * @param t      O score total do #User
 *
*/
void setScore_u (User user, double t) {
  user -> score_u = t;
}

/**
 * @brief        Obtém o score total do #User
 *
 * @param user O #User dado
 * 
 * @return       O score total do #User
*/
double getScore_u (User user) {
  return (user -> score_u);
}

/**
 * @brief        Define o número de viagens do #User
 *
 * @param user   O #User dado
 * @param t      O número de viagens do #User
 *
*/
void setn_viagensU (User user, double t) {
  user -> n_viagensU = t;
}

/**
 * @brief        Obtém o número de viagens do #User
 *
 * @param user   O #User dado
 * 
 * @return       O número de viagens do #User
*/
int getn_viagensU (User user) {
  return (user -> n_viagensU);
}

/**
 * @brief        Define a distância percorrida por um dado #User
 *
 * @param user   O #User dado
 * @param t      Distâmcia percorrida pelo #User
 *
*/
void setDist_t (User user, int t) {
  user -> dist_t = t;
}

/**
 * @brief        Obtém a distância percorrida por um dado #User
 *
 * @param user O #User dado
 * 
 * @return       A distâmcia percorrida pelo #User
*/
int getDist_t (User user) {
  return (user -> dist_t);
}


/**
 * @brief        Define a viagem mais recente do #User
 *
 * @param user O #User dado
 * @param date   A viagem mais recente do #User
 *
*/
void setV_recenteU (User user, Date date) {
  user -> v_recenteU = date;
}


/**
 * @brief        Obtém a viagem mais recente do #Driver
 *
 * @param user   O #User dado
 * 
 * @return       A data da viagem mais recente do #Driver
*/
Date getV_recenteU (User user) {
  return copyDate(user-> v_recenteU);
}

/**
 * @brief        Liberta a memória ocupada por cada campo do User (username, name, pay_method, account_status) e, no fim, ao próprio u
 *
 * @param data   Pointer "data" associado a um User
 *
*/
void delete_user(void* data){
  User u = (User) data;
  FREE(u-> username);
  FREE(u->name);
  FREE(u->pay_method);
  FREE(u->account_status);
  FREE(u);
}

/**
 * @brief       Verifica se um dado #User tem todos os parametros válidos
 *
 * @param line  string com os paremetros de um #User
 *
 * @return      O #User caso todos os parametros sejam válidos e NULL caso contrário
 */
User build_user (char *line){
  User usr = malloc(sizeof(struct user));
  memset(usr,0,sizeof(struct user));
  int i = 0;
  char *buffer;

  while ((buffer = strsep(&line, ";\n")) != NULL) {
  
    switch (i++) {
      case 0:
        if (strlen(buffer)==0) {delete_user(usr); return NULL;} 
        usr->username = strdup(buffer);
        break;
      case 1:
        if (strlen(buffer)==0) {delete_user(usr); return NULL;} 
        usr->name = strdup(buffer);
        break;
      case 2:
        if (! validUserGender(buffer[0])) {delete_user(usr); return NULL;} 
        usr->gender = buffer[0];
        break;
      case 3:
        usr->birth_date = valid_date(buffer);
        if (usr->birth_date == NULL) {delete_user(usr); return NULL;} 
        break;
      case 4:
        usr->account_creation = valid_date(buffer);
        if (usr->account_creation == NULL) {delete_user(usr); return NULL;} 
        break;
      case 5:
        if (! validPayMethod(buffer)) {delete_user(usr); return NULL;} 
        usr->pay_method = strdup(buffer);
        break;
      case 6:
        if (validUserAccountStatus(buffer)==0) {delete_user(usr); return NULL;} 
        usr->account_status = strdup(buffer);
        break;
    }
  
  }
  usr->n_viagensU = 0;
  usr->score_u = 0;
  usr->dist_t = 0;
  usr->total_gasto = 0;
  usr->v_recenteU = NULL; 
  return usr;
}



/**
 * @brief função capaz de colocar todos os users válidos numa hashtable
 *
 * @param ficheiro_entrada  path para o ficheiro que se vai abrir para ser lido
 *
 * @return hashtable com os users
 */
USER_HT* create_UserHt (char* ficheiro_entrada){
  FILE *f;

  f = fopen(ficheiro_entrada, "r");

  if (!f){
    perror("Erro");
    return NULL;
  }

  USER_HT* new = malloc (sizeof(struct user_ht));
  new->users_hash = g_hash_table_new_full(g_str_hash, g_str_equal,NULL,delete_user);

  char line[1000];
  int buffer_size = 1000;

  while(fgets(line, buffer_size, f)) {
      User usr = build_user(strdup(line));
      if (usr != NULL) g_hash_table_insert(new->users_hash, usr->username, usr);
}

  fclose(f);

  return new;
}

/**
 * @brief         Funcão auxiliar liberta da memória a hashtable dos users
 *
 * @param lista   catálogo (hashtable) dos users
 */
void delete_users_hash (USER_HT* lista){
  g_hash_table_destroy(lista->users_hash);
  FREE(lista);
}

/**
 * @brief            Função que acede à hastable dos users e devolve as informações sobre um user a partir do username do mesmo
 *
 * @param lista      catálogo (hashtable) dos users
 * @param username   username de um user
 *
 * @return           user associado ao username dado no input
 */
User q1u (USER_HT* lista, char* username){
  User u = g_hash_table_lookup(lista->users_hash,username);
  return u;
}

/**

*@brief   Função auxiliar que compara dois users com base nas distâncias percorridas
*
*@param a Um pointer para o primeiro user
*
*@param b Um pointer para o primeiro user
*
*@return Se o output for positivo, isso significa que o user "b" tem uma distância total maior que o user "a"
         Se o output for zero, significa que ambos os users têm a mesma distância total
         Se o output for negativo, significa que o user "a" tem uma distância total maior que o user "b"
*/
gint compare_dist(gconstpointer a, gconstpointer b) {
  User u_a = (User) a;
  User u_b = (User) b;

  int dist_a = getDist_t(u_a);
  int dist_b = getDist_t(u_b);
  
  if(dist_a==dist_b && datas_iguais(getV_recenteU(u_a), getV_recenteU(u_b))){
    return strcmp(getUsername(u_a),getUsername(u_b));
  }

  if(dist_a==dist_b){
    return compareDates(getV_recenteU(u_b), getV_recenteU(u_a));
  }
  
  

  return (dist_b-dist_a);
}

/**
 * @brief        Funcão auxiliar que transforma a hashtable numa lista ligada e ordena-a por ordem descrescente da distância percorrida
 *
 * @param table  catálogo (hashtable) dos users
 * 
 * @return       A lista ligada ordenada pela distância percorrida
 */
GList* sort__dist_t (USER_HT* table) {
  
  GList* values = g_hash_table_get_values(table->users_hash);
  
  if (values == NULL) {
    printf("erro");
  }
  
  return g_list_sort(values, compare_dist);
}

