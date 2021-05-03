#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int** alloc(int lignes, int colones){
	int** tab;
	
	tab = malloc(lignes * sizeof(int*));
	for(int i =0;i<lignes;i++){
		tab[i] = malloc(colones * sizeof(int));
	}
	
	return tab;
}

void init(int** tab, int lignes, int colones){
	for(int i=0;i<lignes;i++){
		for(int j=0;j<colones;j++){
			scanf("%d",&tab[i][j]);
		}
	}
}

void liberer(int** tab, int lignes){
	for(int i =0;i<lignes;i++){
			free(tab[i]);
		}
	free(tab);	
}

void afficher(int** tab, int lignes, int colones){
	    for(int i=0; i<lignes; i++){
			printf("+");			
			for(int x=0; x<colones; x++){
				printf("---+");
			}
		    	printf("\n");			
			for(int j=0; j<colones; j++){				
				printf("|");
				if (tab[i][j] == 1){
					printf(" O ");
				}				
				else{
					printf("   ");
				}
			}
			printf("|\n");
		}
		printf("+");			
		for(int x=0; x<colones; x++){
			printf("---+");
		}
		printf("\n");
}

int verifCasesAdjacentes(int** tab, int x, int y, int torique){
	int nbCasesAdjPleines = 0;
	if (torique){

	}
	
	else{
		nbCasesAdjPleines = tab[x-1][y+1] + tab[x][y+1] + tab[x+1][y+1] + tab[x-1][y] + tab[x+1][y] + tab[x-1][y-1] + tab[x][y-1] + tab[x+1][y-1];
	}

	return nbCasesAdjPleines;
}

int nouvellevaleur(int nb_voisin,int valeur_case){
	if(valeur_case == 0){                       // Si la case est vide au départ
		if(nb_voisin == 3){							// Si elle a 3 voisins
			return 1;									// On creé un nouvelle cellule
		}else{										// Sinon
			return 0;									// La case reste vide
		}
	}else{										// Si il y a deja un cellule
		if(nb_voisin == 3 || nb_voisin == 2){		// Si il y a 2 ou 3 voisins
			return 1;									// La cellule reste en vie
		}else{									//Sinon
			return 0;								// La cellule meurt
		}
	}
}

int tour(int** tab,int lignes,int colones,int torique){
	int** t_temp;
	t_temp = alloc(lignes,colones);   //allocation du tableau temporaire

	// initialisation des valeur du tableau temporaire
	for(int i=0;i<lignes;i++){
		for(int j=0;j<colones;j++){
			int nb_voisin = verifCasesAdjacentes(tab,i,j,torique);
			int valeur_case = tab[i][j];
			t_temp[i][j]= nouvellevaleur(nb_voisin,valeur_case);
		}
	}

	tab = t_temp;   // le tableau prend ses nouvelles valeurs

	liberer(t_temp,linges);   // liberation tableau temporaire
}
