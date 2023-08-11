#include "header_el.h"
char ** allouer_data(char ** tab){
	tab = (char**)malloc(1000 * sizeof(char*));
	for(int i = 0 ; i < 1000 ; i++ ){tab[i] = (char*)malloc(257);}
	return tab;
}
int * allouer_split(int * split){
	split = (int*)malloc(50 * sizeof(int));
	for(int i = 0 ; i < 50 ; i++){
		split[i] = 0;
	}
	return split;
}
char ** get_data(char ** tab , int * lignes){
	FILE * fp = fopen("./etudiant.csv","r");
	if(fp != NULL){
		while(fgets(tab[*lignes] , 256 , fp) != NULL){(*lignes)++;}
		printf("BON DEROULEMENT DE LA LECTURE DU FICHIER\n");
	}
	else{printf("ERREUR LORS DE LA LECTURE DU FICHIER !!\n");}
	fclose(fp);
	return tab;
}
void get_nom(Student * mit,char * data , int indices , int * split){
	int i = 0 ; 
	while(data[i] != ','){mit->nom[i] = data[i] ; i++;}
	*split = i+1;
}
void get_pnom(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != ','){mit->pnom[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void get_ddn(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != ','){mit->ddn[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void get_g(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != ','){mit->g[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void get_add(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != ','){mit->add[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void get_parcours(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != ','){mit->parcours[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void get_nationalite(Student * mit, char * data , int indices , int *split){
	int i = 0;
	while(data[*split] != '\n'){mit->nationalite[i] = data[*split] ; i++; (*split)++;}
	(*split)++;
}
void redirection(Student * mit , int lignes){
	FILE * fp = fopen("./etudiant_fait.csv" , "a+");
	char tmp[2000];
	if(fp != NULL){
		system("echo "" > ./etudiant_fait.csv");
		printf("BON DEROULEMENT DE L ECRITURE !!\n");
		fprintf(fp,"Nom complet\tGENRE\tADDRESSE\tDATE DE NAISSANCE\tMENTION\tNATIONALITE\n");
		for(int i = 0 ; i < lignes ; i++){
			sprintf(tmp,"%s %s\t%s\t%s\t%s\t%s\t%s\n ",mit[i].nom,mit[i].pnom,mit[i].g,mit[i].add,mit[i].ddn,mit[i].parcours,mit[i].nationalite);
			fprintf(fp ,"%s" , tmp); 
		}
	}
	else{printf("ERREUR LORS DE L ECRITURE DANS LE FICHIER !!\n");}
	fclose(fp);
}
char ** mise_en_ordre(char ** data , int lignes){
	char tmp[1000];
	for(int i = 0 ; i < lignes ; i ++){
		for(int j = i + 1 ; j < lignes ; j++){
			int k = 0;
			if(data[i][k] == data[j][k]){
				k++;
				if(k == (int)strlen(data[i])||k == (int)strlen(data[j])){break;}
			}
			else if (data[i][k] > data[j][k]){
				strcpy(tmp , data[i]);
				strcpy(data[i] , data[j]);
				strcpy(data[j] , tmp);
			}
		}
	}
	return data;
}
