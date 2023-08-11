#include "header_el.h"
int main(){
	char ** data = NULL;
	data = allouer_data(data);
	int lignes = 0;
	data = get_data(data , &lignes);
	
	int * split = NULL;
	split = allouer_split(split);
	
	data = mise_en_ordre(data , lignes);
	
	Student mit[50];
	for(int i = 0 ; i < lignes ; i++){
		get_nom(&mit[i] ,data[i], i ,&(split[i]));
		get_pnom(&mit[i] , data[i] , i , &(split[i])); 
		get_ddn(&mit[i] , data[i] , i , &(split[i]));
		get_g(&mit[i] , data[i] , i , &(split[i]));
		get_add(&mit[i] , data[i] , i , &(split[i]));
		get_parcours(&mit[i] , data[i] , i , &(split[i]));
		get_nationalite(&mit[i] , data[i] , i , &(split[i]));
	}
	
	redirection(mit, lignes);
	
	return 0;
}
