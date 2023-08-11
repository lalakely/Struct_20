#ifndef ELEVES
#define ELEVES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student{
	char nom[256];
	char pnom[256];
	char ddn[256];
	char g[256];
	char add[256];
	char parcours[256];
	char nationalite[256];
}Student;

char ** allouer_data(char ** tab);
int * allouer_split(int * split);
char ** get_data(char ** tab , int * lignes);
void get_nom(Student * mit,char * data , int indices , int * split);
void get_pnom(Student * mit, char * data , int indices , int *split);
void get_ddn(Student * mit, char * data , int indices , int *split);
void get_g(Student * mit, char * data , int indices , int *split);
void get_add(Student * mit, char * data , int indices , int *split);
void get_parcours(Student * mit, char * data , int indices , int *split);
void get_nationalite(Student * mit, char * data , int indices , int *split);
void redirection(Student * mit , int lignes);
char ** mise_en_ordre(char ** data , int lignes);

#endif
