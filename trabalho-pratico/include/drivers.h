/**
 * @file drivers.h
 * 
 * Este ficheiro contém a declaração de funções auxiliares, referentes ao tipo #Driver
*/
#ifndef DRIVER

#define DRIVER

#include <glib.h>
#include "../include/date.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

typedef struct driver *Driver;

typedef struct drivers_ht DRIVERS_HT;


void setID (Driver driver, int drvid);
int getID (Driver driver);
void setDriverName (Driver driver, char *nm);
char* getDriverName (Driver driver);
void setBirthDay (Driver driver, Date date);
Date getBirthDay (Driver driver) ;
int validDriverGender (char gndr);
void setDriverGender (Driver driver, char gndr);
char getDriverGender (Driver driver);
int validCarClass (char* cc);
void setCarClass (Driver driver, char* cc);
char* getCarClass (Driver driver);
int isDigit (char a);
int isLetter (char a);
int isValidLicensePlate (char* lp);
void setDriverCity (Driver driver, char* ct);
char* getDriverCity (Driver driver);
void setAccountCreationD (Driver driver, Date date);
Date getDriverAccountCreation (Driver driver);
int validDriverAccountStatus (char *as);
void setDriverAccountStatus (Driver driver, char *as);
char* getDriverAccountStatus (Driver driver);
void setTotal_auferido (Driver driver, double t);
double getTotal_auferido (Driver driver);
void setSore_d (Driver driver, double t);
double getScore_d (Driver driver);
void setn_viagensD (Driver driver, int t);
int getn_viagensD (Driver driver);
void setV_recente (Driver driver, Date date);
Date getV_recente (Driver driver);
void setAvaliacao_cidade (Driver driver, double t);
double getAvaliacao_cidade (Driver driver);
void setViagens_cidade (Driver driver, int t);
int getViagens_cidade (Driver driver);

DRIVERS_HT* create_DriversHt (char* ficheiro_entrada);

Driver q1d (DRIVERS_HT* lista, int id);

char* carclass (DRIVERS_HT* lista, int id);

void TESTE2(DRIVERS_HT* lista);

double preco_class (DRIVERS_HT* lista2, int r, int d);

GList* sort_maior_avaliacao_media (DRIVERS_HT* table);

gint compara_avaliacao_media(gconstpointer a, gconstpointer b);

gint compara_avaliacao_media_cidade(gconstpointer a, gconstpointer b);

GList* avaliacao_cidade (DRIVERS_HT* table);

void delete_drivers_hash (DRIVERS_HT* lista);




#endif