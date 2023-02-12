/**
 * @file drivers.c
 *
 * Este ficheiro contém a struct dos drivers, a função que cria um driver válido e a hashtabel com os drivers válidos
*/

#include "../include/drivers.h"
#define FREE(algo) if (algo) free(algo)

/*id;name;birth_day;gender;car_class;license_plate;city;account_creation;account_status*/

/**
 * @brief Type usado para definir um driver
 */
struct driver {

  int id;

  char* name;

  Date birth_day;

  char gender;

  char* car_class;

  char* license_plate;

  char* city;

  Date account_creation;

  char* account_status;

  double total_auferido;

  double score_d;

  int n_viagensD;

  Date v_recente;

  double avaliacao_cidade;

  int viagens_cidade;
};


/**
 * @brief definição de uma hashtable para os drivers
 */
struct drivers_ht{
  GHashTable* drivers_hash;
};


/**
 * @brief        Define o ID do #Driver
 *
 * @param driver O #Driver dado
 * @param dvrid  O ID do #Driver
 *
*/
void setID (Driver driver, int drvid) {
  driver -> id = drvid;
}


/**
 * @brief        Obtém o ID de um #Driver
 *
 * @param driver O #Driver dado
 *
 * @return       O ID do #Driver
 */
int getID (Driver driver) {
  return (driver -> id);
}


/**
 * @brief         Define o nome do #Driver
 *
 * @param driver  O #Driver dado
 * @param nm      O nome do #Driver
 *
*/
void setDriverName (Driver driver, char *nm) {
  driver -> name = strdup (nm);
}


/**
 * @brief         Obtém o nome de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        O nome do #Driver
 */
char* getDriverName (Driver driver) {
  return strdup (driver -> name);
}


/**
 * @brief        Define o o dia de aniversário do #Driver
 *
 * @param driver O #Driver dado
 * @param date   O dia de aniversário do #Driver
 *
*/
void setBirthDay (Driver driver, Date date) {
  driver -> birth_day = copyDate(date);
}


/**
 * @brief         Obtém o dia de aniversário de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        O dia de aniversário do #Driver
 */
Date getBirthDay (Driver driver) {
  return copyDate (driver -> birth_day);
}


/**
 * @brief           Função auxiliar que verifica se o género é válido
 *
 * @param gndr      O género dado
 *
 * @return          1, caso o 'gndr' seja "M" ou "F"; 0, caso contrário
 *
*/
int validDriverGender (char gndr) {
  if ((gndr == 'M') || (gndr == 'F')) return 1;
  else return 0;
}


/**
 * @brief        Define o genero do #Driver
 *
 * @param driver O #Driver dado
 * @param gndr   O genero do #Driver
 *
*/
void setDriverGender (Driver driver, char gndr) {
  if (validDriverGender(gndr)) driver -> gender = gndr;
}


/**
 * @brief         Obtém o genero de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        O genero do #Driver
 */
char getDriverGender (Driver driver) {
  return driver -> gender;
}


/**
 * @brief     Função auxiliar que verifica se a classe do carro é válida
 *
 * @param cc  O classe do carro dado
 *
 * @return    1 caso o 'cc' seja "BASIC" ou "PREMIUM" ou "GREEN", 0 caso contrário
 *
*/
int validCarClass (char* cc) {
  char* cc1 = "BASIC";
  char* cc2 = "PREMIUM";
  char* cc3 = "GREEN";
  unsigned i;
  for (i=0; i<strlen(cc); i++) {
    cc[i] = toupper(cc[i]);
  }
  if ((strcmp (cc, cc1)==0) || (strcmp (cc, cc2)==0) || (strcmp (cc,cc3)==0)) return 1;
  else return 0;
}


/**
 * @brief        Define classe do carro do #Driver
 *
 * @param driver O #Driver dado
 * @param gndr   A classe do carro do #Driver
 *
*/
void setCarClass (Driver driver, char* cc) {
  if (validCarClass (cc)) driver -> car_class = strdup(cc);
}


/**
 * @brief         Obtém a classe do carro de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        A classe do carro do #Driver
 */
char* getCarClass (Driver driver) {
  return strdup(driver -> car_class);
}


/**
 * @brief    Função auxiliar que verifica se um char é um digito
 *
 * @param a  Um caracter
 *
 * @return    1 se '0'<=a<='9', 0 caso contrário
 */
int isDigit (char a) {
  if (a >= '0' && a <= '9') return 1;
  else return 0;
}


/**
 * @brief    Função auxiliar que verifica se um char é uma letra
 *
 * @param a  Um caracter
 *
 * @return    1 se 'A'<=a<='Z' ou 'a'<=a<='z', 0 caso contrário
 */
int isLetter (char a) {
  if ((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')) return 1;
  else return 0;
}



/**
 * @brief     Função auxiliar que verifica se a matricula é válida
 *
 * @param lp   Matricula do carro
 *
 * @return  Retorna 1 se a matricula for válida e 0 caso contrário
 *
*/
// NN-CC-NN ; CC-NN-NN ; NN-NN-CC
int isValidLicensePlate (char* lp) {

  if (strlen(lp) != 8 || (lp[2] != '-') || (lp[5] != '-')) return 0;
  int digitos, letras;
  unsigned i;

  for (i = 0; i < strlen(lp); i++) {

    if (isLetter(lp[i])) {
      if (lp[i] == toupper(lp[i])) letras++;
    }

    if (isDigit(lp[i])) digitos++;

    if (i == 2) {
      if (digitos != 2 || letras !=2) return 0;
    }

    if (i == 4) {
      if ((digitos != 2 || letras != 2) && (digitos != 4)) return 0;
    }
  }
  if (digitos == 4 && letras == 2) return 1;
  else return 0;
}


/**
 * @brief        Define a cidade do #Driver
 *
 * @param driver O #Driver dado
 * @param gndr   A cidade do #Driver
 *
*/
void setDriverCity (Driver driver, char* ct) {
  driver -> city = strdup (ct);
}


/**
 * @brief         Obtém a cidade de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        A cidade do #Driver
 */
char* getDriverCity (Driver driver) {
  return (driver -> city);
}


/**
 * @brief        Define a data de criação da conta do #Driver
 *
 * @param driver O #Driver dado
 * @param gndr   A data de criação da conta do #Driver
 *
*/
void setAccountCreationD (Driver driver, Date date) {
   driver -> account_creation = copyDate (date);
}


/**
 * @brief         Obtém a data de criação da conta de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        A data de criação da conta do #Driver
 */
Date getDriverAccountCreation (Driver driver) {
   return copyDate (driver -> account_creation);
}


/**
 * @brief     Função auxiliar que valida a data de criação da conta
 *
 * @param as  A data de criação da conta
 *
 * @return    1 se 'as' for "ACTIVE" ou "INACTIVE", 0 caso contrário
 */
int validDriverAccountStatus (char *as) {
  char as1[] = "ACTIVE" , as2[] = "INACTIVE";
  unsigned i;
  for (i=0; i<strlen(as); i++) {
    as[i] = toupper(as[i]);
  }
  if ((strcmp (as, as1)==0) || (strcmp (as, as2)==0)) return 1;
  else return 0;
}

/**
 * @brief        Define o estado da conta do #Driver
 *
 * @param driver O #Driver dado
 * @param gndr   O estado da conta do #Driver
 *
*/
void setDriverAccountStatus (Driver driver, char *as) {
  if (validDriverAccountStatus (as)) driver->account_status = strdup(as);
}


/**
 * @brief         Obtém o estado da conta de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        O estado da conta do #Driver
 */
char* getDriverAccountStatus (Driver driver) {
  return strdup(driver->account_status);
}

/**
 * @brief        Define o total auferido de um #Driver
 *
 * @param driver O #Driver dado
 * @param t      O total auferido do #Driver
 *
*/
void setTotal_auferido (Driver driver, double t) {
  driver -> total_auferido = t;
}

/**
 * @brief         Obtém o total auferido de um #Driver
 *
 * @param driver  O #Driver dado
 *
 * @return        O total auferido de um #Driver
 */
double getTotal_auferido (Driver driver) {
  return (driver -> total_auferido);
}

/**
 * @brief        Define o score total do #Driver
 *
 * @param driver O #Driver dado
 * @param t      O score total do #Driver
 *
*/
void setSore_d (Driver driver, double t) {
  driver -> score_d = t;
}

/**
 * @brief        Obtém o score total do #Driver
 *
 * @param driver O #Driver dado
 * 
 * @return       O score total do #Driver
*/
double getScore_d (Driver driver) {
  return (driver -> score_d);
}

/**
 * @brief        Define o número de viagens do #Driver
 *
 * @param driver O #Driver dado
 * @param t      O número de viagens do #Driver
 *
*/
void setn_viagensD (Driver driver, int t) {
  driver -> n_viagensD = t;
}

/**
 * @brief        Obtém o número de viagens do #Driver
 *
 * @param driver O #Driver dado
 * 
 * @return       O número de viagens do #Driver
*/
int getn_viagensD (Driver driver) {
  return (driver -> n_viagensD);
}


/**
 * @brief        Define a viagem mais recente do #Driver
 *
 * @param driver O #Driver dado
 * @param date   A viagem mais recente do #Driver
 *
*/
void setV_recente (Driver driver, Date date) {
  driver -> v_recente = date;
}

/**
 * @brief        Obtém a viagem mais recente do #Driver
 *
 * @param driver O #Driver dado
 * 
 * @return       A data da viagem mais recente do #Driver
*/
Date getV_recente (Driver driver) {
  return copyDate(driver -> v_recente);
}



/**
 * @brief        Define a avaliação total de um #Driver numa certa cidade
 *
 * @param driver O #Driver dado
 * @param t      A avaliação total de um #Driver numa certa cidade
 *
*/
void setAvaliacao_cidade (Driver driver, double t) {
  if (driver == NULL) {
    return;
  }
  driver -> avaliacao_cidade = t;
}

/**
 * @brief        Obtém a avaliação total de um #Driver numa certa cidade
 *
 * @param driver O #Driver dado
 * 
 * @return       A avaliação total de um #Driver numa certa cidade
*/
double getAvaliacao_cidade (Driver driver) {
  return (driver -> avaliacao_cidade);
}

/**
 * @brief        Define o número de viagens de um #Driver numa certa cidade
 *
 * @param driver O #Driver dado
 * @param t      O número de viagens de um #Driver numa certa cidade
 *
*/
void setViagens_cidade (Driver driver, int t) {
  if (driver == NULL) {
    return;
  }
  driver -> viagens_cidade = t;
}

/**
 * @brief        Obtém o número de viagens de um #Driver numa certa cidade
 *
 * @param driver O #Driver dado
 * 
 * @return       O número de viagens de um #Driver numa certa cidade
*/
int getViagens_cidade (Driver driver) {
  return (driver -> viagens_cidade);
}

/**
 * @brief        Liberta a memória ocupada por cada campo do Driver (name, car_class, license_plate, city, account_status) e, no fim, ao próprio d
 *
 * @param data   Pointer "data" associado a um Driver
 *
*/
void delete_driver(void* data){
  Driver d = (Driver) data;
  FREE(d-> name);
  FREE(d->car_class);
  FREE(d->license_plate);
  FREE(d->city);
  FREE(d->account_status);
  FREE(d);
}


/**
 * @brief       Verifica se um dado #Driver tem todos os parametros válidos
 *
 * @param line  string com os paremetros de um #Driver
 *
 * @return      O #Driver caso todos os parametros sejam válidos e NULL caso contrário
 */
Driver build_driver (char *line){
  Driver drv = malloc(sizeof(struct driver));
  memset(drv,0,sizeof(struct driver));
  int i = 0;
  char *buffer;

  while ((buffer = strsep(&line, ";\n")) != NULL) {
    // int aux;
    switch (i++) {
      case 0:
        if (strlen(buffer)==0){delete_driver(drv); return NULL;}
        drv->id = atoi(buffer);
        break;
      case 1:
        if (strlen(buffer)==0) {delete_driver(drv); return NULL;}
        drv->name = strdup(buffer);
        break;
      case 2:
        drv->birth_day = valid_date(buffer);
        if (drv->birth_day == NULL) {delete_driver(drv); return NULL;}
        break;
      case 3:
        if (! validDriverGender(buffer[0])) {delete_driver(drv); return NULL;}
        drv->gender = buffer[0];
        break;
      case 4:
        if (strlen(buffer)==0) {delete_driver(drv); return NULL;}
        drv->car_class = strdup(buffer);
        break;
      case 5:
        if (strlen(buffer)==0) {delete_driver(drv); return NULL;}
        drv->license_plate = strdup(buffer);
        break;
      case 6:
        if (strlen(buffer)==0) {delete_driver(drv); return NULL;}
        drv->city = strdup(buffer);
        break;
      case 7:
        drv->account_creation = valid_date(buffer);
        if (drv->account_creation == NULL) {delete_driver(drv); return NULL;}
        break;
      case 8:
        if (validDriverAccountStatus(buffer)==0) {delete_driver(drv); return NULL;}
        drv->account_status = strdup(buffer);
        break;
    }
  }
  drv->n_viagensD = 0;
  drv->score_d = 0;
  drv->avaliacao_cidade = 0;
  drv->viagens_cidade = 0;
  drv->v_recente =NULL; 
  return drv;
}


/**
 * @brief Função que coloca todos os drivers válidos numa hashtable
 *
 * @param ficheiro_entrada path para o ficheiro que se vai abrir para ser lido
 *
 * @return catálogo (hashtable) com todos os drivers
 */
DRIVERS_HT* create_DriversHt (char* ficheiro_entrada){
  FILE *f;

  f = fopen(ficheiro_entrada, "r");

  if (!f){
    perror("Erro");
    return NULL;
  }

  DRIVERS_HT* new = malloc (sizeof(struct drivers_ht));
  new->drivers_hash = g_hash_table_new_full(g_int_hash, g_int_equal,NULL,delete_driver);

  char line[1000];
  int buffer_size = 1000;

  while(fgets(line, buffer_size, f)) {

      Driver dvr = build_driver(strdup(line));
      
      if (dvr != NULL) {
        g_hash_table_insert(new->drivers_hash, &dvr->id, dvr);
      } 
}

  fclose(f);

  return new;
}

/**
 * @brief         Funcão auxiliar liberta da memória a hashtable dos drivers
 *
 * @param lista   catálogo (hashtable) dos drivers
 */
void delete_drivers_hash (DRIVERS_HT* lista){
  g_hash_table_destroy(lista->drivers_hash);
  FREE(lista);
}


/**
 * @brief Função que acede à hastable dos drivers e devolve as informações sobre um condutor a partir do id do mesmo
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param id   id de um driver
 *
 * @return driver associado ao id dado no input
 */
Driver q1d (DRIVERS_HT* lista, int id){
  int *y = &id;
  Driver d = g_hash_table_lookup(lista->drivers_hash,y);
  return d;
}

/**
 * @brief Função que acede à hastable dos drivers e devolve as informações sobre um condutor a partir do id do mesmo
 *
 * @param lista catálogo (hashtable) dos drivers
 * @param id  id de um driver
 *
 * @return classe do carro do condutor desejado
 */
char* carclass (DRIVERS_HT* lista, int id){
  int *y = &id;
  Driver d = g_hash_table_lookup(lista->drivers_hash,y);
  // printf("%s\n",d->car_class);
  return d->car_class;
  
}

/**
 * @brief Função que calcula o preço de uma viagem, com uma certa distância, e com uma certa classe de carro
 *
 * @param lista2   catálogo (hashtable) dos drivers
 * @param id       id de um driver
 * @param d        distância
 *
 * @return o preço
 */
double preco_class (DRIVERS_HT* lista2, int id, int d) {

  double p;
  char* class = carclass(lista2, id);
  
  if (strcmp(class, "basic") == 0) {
    p = (3.25 + (0.62 * d));
  }
  if (strcmp(class, "green") == 0) {
    p = (4.0 + (0.79 * d));
  }
  if (strcmp(class, "premium") == 0) {
    p = (5.20 + (0.94 * d));
  }

  return p;
}



/**

*@brief Função auxiliar que compara dois condutores com base na sua classificação média e na data da sua viagem mais recente.
*
*@param a Um pointer para o primeiro condutor.
*
*@param b Um pointer para o segundo condutor.
*
*@return Um número inteiro indicando o resultado da comparação. O valor >0 indica que o segundo condutor 
*        tem uma pontuação mais alta e/ou uma viagem mais recente que o primeiro. 
*        O valor <0 indica que o primeiro condutor tem uma pontuação mais alta e/ou uma viagem mais recente que o segundo. 
*        O valor 0 indica que os condutores são iguais tanto na pontuação quanto na data da viagem mais recente.

*/
gint compara_avaliacao_media(gconstpointer a, gconstpointer b) {
  Driver d_a = (Driver) a;
  Driver d_b = (Driver) b;
  
  double scoreA = ((double)d_a->score_d/d_a->n_viagensD);
  double scoreB = ((double) d_b->score_d/d_b->n_viagensD);
  
  
  if (scoreB == scoreA && datas_iguais(getV_recente(d_a),getV_recente(d_b))){
      return (getID(d_b)) - (getID(d_a));
  }
  
  if (scoreB == scoreA) {
      return compareDates(getV_recente(d_b), getV_recente(d_a));
  }
  if(scoreB > scoreA){
    return 1;
  }
  return -1;
} 


/**
 * @brief     Funcão auxiliar que compara dois condutores com base na sua classificação média numa cidade específica.
 *
 * @param a   Um pointer para o primeiro condutor.
 * @param b   Um pointer para o segundo condutor.
 *
 * @return    Um número inteiro indicando o resultado da comparação. 
 *            O valor de >0 indica que o segundo condutor tem uma pontuação mais alta na cidade específica do que o primeiro. 
 *            O valor de <0 indica que o primeiro condutor tem uma pontuação mais alta na cidade específica do que o segundo. 
 *            O valor de 0 indica que os condutores são iguais na sua pontuação na cidade específica.
 */
gint compara_avaliacao_media_cidade(gconstpointer a, gconstpointer b) {
  Driver d_a = (Driver) a;
  Driver d_b = (Driver) b;

  double scoreA =((double)getAvaliacao_cidade(d_a)/getViagens_cidade(d_a));
  double scoreB = ((double)getAvaliacao_cidade(d_b)/getViagens_cidade(d_b));

  if (scoreB == scoreA){
      return (getID(d_b)) - (getID(d_a));
  }

  if(scoreB > scoreA){
    return 1;
  }
  return -1;
}


/**
 * @brief         Funcão auxiliar que transforma a hastable numa lista ligada e ordena-a por ordem descrescente de avaliação média
 *
 * @param table   catálogo (hashtable) dos drivers
 *
 * @return        A lista ligada ordenada pela avaliação média
 */
GList* sort_maior_avaliacao_media (DRIVERS_HT* table) {
  
  GList* values = g_hash_table_get_values(table->drivers_hash);
  
  if (values == NULL) {
    printf("erro");
  }
  values = g_list_sort(values, compara_avaliacao_media);
  return values;
}

/**
 * @brief         Funcão auxiliar que transforma a hastable numa lista ligada e ordena-a por ordem descrescente da avaliação média numa determinada cidade
 * 
 * @param table   catálogo (hashtable) dos drivers
 *
 * @return        A lista ligada ordenada pela avaliação média numa determinada cidade
 */
GList* avaliacao_cidade (DRIVERS_HT* table) {
  
  GList* values = g_hash_table_get_values(table->drivers_hash);
  
  if (values == NULL) {
    printf("erro");
  }

  values = g_list_sort(values, compara_avaliacao_media_cidade);
  
  return values;
}


