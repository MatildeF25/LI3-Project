/**
 * @file date.c
 *
 * Este ficheiro contém a implementação do tipo #Date
 *
 * O tipo #Date é usado para representar a data ou tempo
*/

#include "../include/date.h"
#define ref_date {0,0,0,9,10,2022,0,0,0,0}

/**
 * @brief Type usado para definir uma data
 */
struct date{
    char *day, *month, *year;
};


/**
 * @brief           Função auxiliar que compara duas #Date
 *
 * @param date1     Primeira #Date
 * @param date2     Segunda #Date
 * @return          '0' se date1 == date2, -1 se data1 for antes da data2 e 1 caso contrário
*/

int compareDates(Date date1, Date date2) {
    if (date1 == NULL && date2 == NULL) {
        return 0;
    }
    
    else if (!date1 && date2) // mesmo que date1==NULL && date2 != NULL
      return 1;
    
    else if (!date2 && date1)
      return -1;

    if (atoi(date1->year) < atoi(date2->year)) return -1;
    if (atoi(date1->year) > atoi(date2->year)) return 1;

    if (atoi(date1->month) < atoi(date2->month)) return -1;
    if (atoi(date1->month) > atoi(date2->month)) return 1;

    if (atoi(date1->day) < atoi(date2->day)) return -1;
    if (atoi(date1->day) > atoi(date2->day)) return 1;
    return 0;
}



/**
 * @brief função que verifica se uma data está válida
 *
 * @param uma data (string)
 *
 * @return a mesma data se esta for válida
 */
Date valid_date (char *date_str){
    if (strlen(date_str) != 10 || date_str[2] + date_str[5] != 2*'/') return NULL; // se o comprimento da str for diferente de 10 (dd/mm/aaaa)ou os caracteres 2 e 5 nao forem '/' não é valida
    for (int i=0 ; date_str[i] ; i++)
    {
        if (i==2 || i==5) continue;
        if (date_str[i]<'0' || date_str[i]>'9') return NULL; // se algum dos outros caracteres nao for numero não é valido
    }

    Date date = malloc(sizeof(struct date));

    date->day = strsep(&date_str, "/");
    date->month = strsep(&date_str, "/");
    date->year  = strsep(&date_str, " ");
    
   

    if((atoi(date->year))>=1900 && atoi((date->year))<=9999)
    {
        //check month
        if(atoi((date->month))>=1 && atoi((date->month))<=12)
        {
            if(atoi(date->day)>=1 && atoi(date->day)<=31){
                return date;
            }
            else return NULL;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
    return date;
}



/**
 * @brief           Define o dia(day), mês(month), ou ano(year) de um #Date
 *
 * @param date      O #Date dado
 * @param day       O novo dia do #Date
 * @param month     O novo mês dp #Date
 * @param year      O novo ano do #Date
*/
void setDate1 (Date date, char* day, char* month, char* year) {
    date = malloc(sizeof(struct date));
    date -> day   = day;
    date -> month = month;
    date -> year  = year;
}


/**
 * @brief função que copia uma data (objetivo de uso é encapsulamento)
 *
 * @param Data
 *
 * @return cópia da data desejada
 */
Date copyDate (Date date) {
    if (date == NULL){
        return NULL;
    }
    Date result = (Date)malloc(sizeof(struct date));
    *result = *date;
    return result;
}


/**
 * @brief       Obtém o dia de um #Date
 *
 * @param date  #Date dado
 *
 * @return      O dia do #Date
*/
char* getDateDay (Date date) {
    return date->day;
}


/**
 * @brief       Obtém o mês de um #Date
 *
 * @param date  #Date dado
 *
 * @return      O mês do #Date
*/
char* getDateMonth (Date date) {
    return date->month;
}


/**
 * @brief       Obtém o ano de um #Date
 *
 * @param date  #Date dado
 *
 * @return      O ano do #Date
*/
char* getDateYear (Date date) {
    return date->year;
}


/**
 * @brief       Define o dia de um #Date
 *
 * @param date  #Date dado
 * @param day   O novo dia do #Date
*/
void setDateDay (Date date, char* day) {
    date->day = day;
}


/**
 * @brief         Define o mês de um #Date
 *
 * @param date    #Date dado
 * @param month   O novo mês do #Date
*/
void setDateMonth (Date date, char* month) {
    date->month = month;
}


/**
 * @brief         Define o ano de um #Date
 *
 * @param date    #Date dado
 * @param year    O novo ano do #Date
*/
void setDateYear (Date date, char* year) {
    date->year = year;
}

/**
 * @brief Função que converte um type date para uma string
 *
 * @param date  #Date dado
 *
 * @return A mesma data mas em string
 */
char* convert_date_to_string (Date date){
    char* date_string = malloc(sizeof(char) * 11);
    
    sprintf(date_string, "%s/%s/%s", date->day, date->month, date->year);
    return date_string;
}



/**
 * @brief   Função auxiliar que calcula a idade de um indivíduo a partir da data de nascimento
 *
 * @param date  #Date dado
 *
 * @return  idade
 */
int idade (Date date){
    struct tm data_hora_atual = ref_date;


    int idade = (data_hora_atual.tm_year) - atoi(date->year);
    if (data_hora_atual.tm_mon+1 < atoi(date->month)){
        idade--;
    }else if(data_hora_atual.tm_mon+1 == atoi(date->month)){
        if(data_hora_atual.tm_mday < atoi(date->day)){
            idade--;
        }
    }

    return idade;
}



/**
 * @brief   Função auxiliar que verifica a data mais recente
 *
 * @param data1  #Date 
 * @param data2  #Date 
 * 
 * @return  Retorna '1' se a "data1" for anterior à "data2" (return 0 caso contrário)
 */
int menor(Date data1, Date data2)
{
    if(data1==NULL) return 1;
  int year1 = atoi(data1->year),year2 = atoi(data2->year);
  if (year1 < year2) return 1;
  int month1 = atoi(data1->month), month2 = atoi(data2->month);
  if (year1 == year2 && month1 < month2) return 1;
  int day1 = atoi(data1->day), day2 = atoi(data2->day);
  if (year1 == year2 && month1 == month2 && day1 <= day2) return 1;
  return 0;
}


/**
 * @brief   Função auxiliar que verifica se uma #Date está entre outras duas
 *
 * @param date  #Date dado
 * @param date1 #Date minima
 * @param date2 #Date maxima
 *
 * @return  Retorna 1 se estiver "date" entre a "date1" e a "date2"
 */
int entre_datas(Date date, Date date1, Date date2)
{
  if(datas_iguais(date1,date)==1 || datas_iguais(date2,date)==1){
    return 0;
  }
  else{
    return menor(date1, date) && menor(date, date2); 
  }
  
}


/**
 * @brief   Função auxiliar que verifica se uma #Date está entre outras duas, sendo que se for igual, a data é incluída na solução
 *
 * @param date  #Date dado
 * @param date1 #Date minima
 * @param date2 #Date maxima
 *
 * @return  Retorna 1 se estiver "date" entre a "date1" e a "date2"
 */
int entre_datas_incluindo(Date date, Date date1, Date date2)
{
    return menor(date1, date) && menor(date, date2); 
}


/**
 * @brief   Função auxiliar que verifica se as datas são iguais
 *
 * @param date1  #Date 
 * @param date2  #Date 
 * 
 * @return  Retorna '1' se as datas forem iguais e '0' se as datas forem diferentes
 */
int datas_iguais (Date date1, Date date2){
    if(date1 == NULL && date2 == NULL){
        return 1;
    }
    else if (date1 == NULL || date2 == NULL)
      return 0;

    if (atoi(date1->day) == atoi(date1->day) && atoi(date1->month) == atoi(date2->month) && atoi(date1->year) == atoi(date2->year)){
        return 1;
    }
    else return 0; 
}