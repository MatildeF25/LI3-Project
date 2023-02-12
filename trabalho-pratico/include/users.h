/**
 * @file users.h
 *
 * Este ficheiro contém a declaração de funções auxiliares, referentes ao tipo #User 
*/
#ifndef _USER_H_

#define _USER_H_

#include <glib.h>
#include "../include/date.h"
#include "../include/users.h"
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


/**
 * @brief Estrutura usada para o tipo #User
*/
typedef struct user *User;

typedef struct user_ht USER_HT;

//typedef enum cuser {

//} CUSER;char* getGender (User);


void setUsername (User user, char *usr);
char* getUsername (User user);
void setUserXName (User user, char *nm);
char* getUserXName (User user);
int validUserGender (char gndr);
void setUserGender (User user, char gndr);
char getUserGender (User user);
void setBirthDate (User user, Date date);
Date getBirthDate (User user);
void setUserAccountCreation (User user, Date date);
Date getUserAccountCreation (User user);
int validPayMethod (char *pm);
void setPayMethod (User user, char *pm);
char* getPayMethod (User user);
int validUserAccountStatus (char *as);
void setUserAccountStatus (User user, char *as);
char* getUserAccountStatus (User user);
void setTotal_gasto (User user, double t);
double getTotal_gasto (User user);
void setScore_u (User user, double t);
double getScore_u (User user);
void setn_viagensU (User user, double t);
int getn_viagensU (User user);
void setDist_t (User user, int t);
int getDist_t (User user);
void setV_recenteU (User user, Date date);
Date getV_recenteU (User user);


int print_user_info (User user);
void print (User u);


USER_HT* create_UserHt(char* ficheiro_entrada);

User q1u (USER_HT* lista, char* username);

gint compare_dist(gconstpointer a, gconstpointer b);
GList* sort__dist_t (USER_HT* table);

void delete_users_hash (USER_HT* lista);


#endif
