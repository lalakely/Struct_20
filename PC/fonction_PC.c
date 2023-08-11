#include "header.h"
char ** allocation(char** tab){
	tab = (char**)malloc(1000 * sizeof(char*));
	for(int i = 0 ; i  < 1000 ; i ++){tab[i] = (char*)malloc(257);}
	return tab;
}
char ** get_alldata_from_file(char ** tab , int * nombre_de_lignes){
	FILE * fp = fopen("./fichier_struct_PC_get.csv","r");
	int i = 0 ;
	if(fp != NULL){
		while(fgets(tab[i] , 256 , fp ) != NULL){i++;}
		printf("BON DEROULEMENT DE LA LECTURE !! \n");
	}
	else{printf("ERREUR DE LA LECTURE DU FICHIER !!"); exit(1);}
	fclose(fp);
	*nombre_de_lignes = i;
	return tab;
}
void get_macs(Pc * p,char * tab , int indice , int * split){
	int i = 0 ;
	while(tab[i] != '/'){p->mac[i] = tab[i] ; i++;}
	split[indice] = i + 1;
}
void get_label(Pc * p , char * tab , int indice , int * split){
	int i = 0 ; 
	while(tab[split[indice]] != '/'){p->label[i] = tab[split[indice]] ; i++ ; split[indice]++;}
	split[indice]++;
}
void get_marque(Pc * p , char * tab , int indice , int * split){
	int i = 0 ; 
	while(tab[split[indice]] != '\n'){p->marque[i] = tab[split[indice]] ; i++ ; split[indice]++;}
}
void affichage_vers_fichier(char ** data , int nombre_de_lignes){
	FILE * fp = fopen("./fichier_struct_PC_put.csv" , "a+");
	if(fp != NULL){
		system("echo "" > ./fichier_struct_PC_put.csv");
		printf("BON DEROULEMENT DE L ECRITURE DANS LE FICHIER !!\n ");
		fprintf(fp,"Nom\tMARQUE\tMAC\n");
		for(int i = 0 ; i < nombre_de_lignes ; i++){
			fprintf(fp,"%s",data[i]);
		}
	}
	else{printf("ERREUR LORS DE L ECRITURE DANS LE FICHIER !! \n");}
	fclose(fp);
}
char ** rearrangement(char ** data,Pc PC_eleves[46], int nombre_de_lignes){
	for(int i = 0 ; i < nombre_de_lignes ; i++){
		sprintf(data[i],"%s\t%s\t%s\t\n",PC_eleves[i].label,PC_eleves[i].marque,PC_eleves[i].mac);
	}
	for(int i = 0 ; i < nombre_de_lignes ; i++){
		for(int j = i + 1 ; j < nombre_de_lignes ; j++){
			char tmp[1000];
			int k = 0;
			if(data[i][k] == data[j][k]){
				k ++;
				if(k == (int)strlen(data[i])||k == (int)strlen(data[j])){break;}
			}
			if(data[i][k] > data[j][k]){
				strcpy(tmp ,data[i]);
				strcpy(data[i] , data[j]);
				strcpy(data[j] , tmp);
			}
		}
	}
	return data;
}
