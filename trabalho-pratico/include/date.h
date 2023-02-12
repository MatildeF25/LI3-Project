/**
 * @file date.h
 * 
 * Este ficheiro contém a declaração de funções auxiliares, referentes ao tipo #Date 
*/
#ifndef DATE

#define DATE


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>


typedef struct date *Date;
struct tm;

int compareDates (Date date1, Date date2);
Date valid_date (char *date_str);
void setDate1 (Date date, char* day, char* month, char* year);
Date copyDate (Date date);
char* getDateDay (Date date);
char* getDateMonth (Date date);
char* getDateYear (Date date);
void setDateDay (Date date, char* day);
void setDateMonth (Date date, char* month);
void setDateYear (Date date, char* year);
char* convert_date_to_string (Date date);
int idade (Date date);
Date copyDate (Date date);
int menor(Date data1, Date data2);
int entre_datas (Date date, Date date1, Date date2);
int entre_datas_incluindo(Date date, Date date1, Date date2);
int datas_iguais (Date date1, Date date2);

#endif
