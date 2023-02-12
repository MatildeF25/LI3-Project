/**
 * @file prints.h
 * 
 * Este ficheiro contém a declaração das funções usadas para a execução do menu
*/
#ifndef PRINTS
#define PRINTS

#include "../include/users.h"
#include "../include/drivers.h"
#include "../include/rides.h"



void printMenu();

void print_q1users (USER_HT* lista, char* username);
void print_q1driver (DRIVERS_HT* lista, int id);
void print_q2 (DRIVERS_HT* lista, int N);
void print_q3 (USER_HT* lista, int N);
void print_q4 (RIDES_HT* lista, DRIVERS_HT* lista2, char* cidade);
void print_q5 (RIDES_HT* lista, DRIVERS_HT* lista2, char* data1, char* data2);
void print_q6 (RIDES_HT* lista, char* cidade ,char* data1, char* data2);
void print_q7 (DRIVERS_HT* lista, int N);
void print_q8 (RIDES_HT* lista, DRIVERS_HT* lista2, USER_HT* lista3, char g, int anos);
void print_q9 (RIDES_HT* lista, char* data1, char* data2);


#endif