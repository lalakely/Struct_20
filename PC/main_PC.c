#include "header.h"
int main(){
	int nombre_de_lignes = 0;
	char ** PC_get = NULL;
	PC_get = allocation(PC_get);
	PC_get = get_alldata_from_file(PC_get , &nombre_de_lignes);
	
	int split[50];
	
	Pc PC_eleves[46]; 
	for(int i = 0 ; i < nombre_de_lignes ; i++){
		get_macs(&PC_eleves[i] , PC_get[i] , i , &split[i]);
		get_label(&PC_eleves[i] , PC_get[i] , i , &split[i]);
		get_marque(&PC_eleves[i] , PC_get[i] , i , &split[i]);
	}
	char ** data_abc = NULL;
	data_abc = allocation(data_abc);
	data_abc = rearrangement(data_abc ,PC_eleves , nombre_de_lignes);
	affichage_vers_fichier(data_abc , nombre_de_lignes);
	return 0;
}
