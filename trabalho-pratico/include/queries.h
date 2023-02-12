/**
 * @file queries.h
 *
 * Este ficheiro contém a declaração das funções usadas para a execução das queries
*/
#ifndef QUERIES

#define QUERIES

#include <glib.h>
#include "../include/users.h"
#include "../include/drivers.h"
#include "../include/rides.h"
#include "../include/date.h"
#include <stdio.h>
#include <stdlib.h>






void q1users (USER_HT* lista, char* username, int num);
void q1driver (DRIVERS_HT* lista, int id, int num);

void q4 (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade, int num);

void q5 (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2, int num);

void q6 (RIDES_HT* lista, char* cidade ,char* data1, char* data2, int num);

void q2 (DRIVERS_HT* lista, int N, int num);

void q3 (USER_HT* lista, int N, int num);

void q7 (DRIVERS_HT* lista, int N, int num);

void q7_vazia (DRIVERS_HT* lista, int N, int num);

void q8 (RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3 ,char g, int anos, int num);

void q9 (RIDES_HT* lista, char* data1, char* data2, int num);

#endif
