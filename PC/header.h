#ifndef C
#define C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Pc{
	char mac[256];
	char label[256];
	char marque[256];
}Pc;
char ** allocation(char** tab);
char ** get_alldata_from_file(char ** tab , int * nombre_de_lignes);
void get_macs(Pc * p,char * tab , int indice , int * split);
void get_label(Pc * p , char * tab , int indice , int * split);
void get_marque(Pc * p , char * tab , int indice , int * split);
void affichage_vers_fichier(char ** data , int nombre_de_lignes);
char ** rearrangement(char ** data,Pc PC_eleves[46], int nombre_de_lignes);
#endif 
