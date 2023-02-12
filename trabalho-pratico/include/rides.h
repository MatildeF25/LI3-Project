/**
 * @file rides.h
 * 
 * Este ficheiro contém a declaração de funções auxiliares, referentes ao tipo #Rides
*/
#ifndef RIDES

#define RIDES

#include <glib.h>
#include "../include/date.h"
#include "../include/users.h"
#include "../include/drivers.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct rides *Rides;

typedef struct rides_ht RIDES_HT;


void setIDRides (Rides rides, int iD);
int getIDRides (Rides rides);
void setDate (Rides rides, Date date);
Date getDate (Rides rides);
void setdriver (Rides rides, int iD_driver);
void setUser (Rides rides, char* usr);
void setCity (Rides rides, char* ct);
char* getCity (Rides rides);
int validDistance (int dst);
void setDistance (Rides rides, int dst);
int elem (int x, int v[], int N);
int validScore (int scr);
void setUserScore (Rides rides, int scr);
int getUserScore (Rides rides);
int validDriverScore (double ds) ;
void setDriverScore (Rides rides, int scr);
double getDriverScore (Rides rides);
void setTip (Rides rides, double tp);
void setComment (Rides rides, char* cmnt);
char* getComment (Rides rides);
char* getUser (Rides rides);
int getdriver (Rides rides);
int getDistance (Rides rides);
double getTip (Rides rides);

RIDES_HT* create_RidesHt (char* ficheiro_entrada, USER_HT* lista, DRIVERS_HT* lista2);

double preco_medio (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade);

double preco_medio_entre_datas (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2);

double distancia_medio (RIDES_HT* lista, char* cidade ,char* data1, char* data2);

void set_v (RIDES_HT* lista, DRIVERS_HT* lista2);

void viagem_recente_d (RIDES_HT* lista, DRIVERS_HT* lista2);

int avaliacao_t_cidade (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade);

void viagens_por_cidade (RIDES_HT* lista, DRIVERS_HT* lista2 ,char* cidade);

void delete_rides_hash (RIDES_HT* lista);

GList* list_rides (RIDES_HT* lista, char* date1, char* date2);

gint compara_distancia(gconstpointer a, gconstpointer b);

GList* sort_menor_dist (RIDES_HT* table, char* data1, char* data2);

gint conta_mais_antiga (gconstpointer a, gconstpointer b);

GList* sort_conta_mais_antiga(RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3, char g, int anos);

#endif