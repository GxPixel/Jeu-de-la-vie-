#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int** alloc(int nb_ligne, int nb_colone){
	int** tab;
	
	tab = malloc(nb_ligne * sizeof(int*));
	for(int i =0;i<nb_ligne;i++){
		tab[i] = malloc(nb_colone * sizeof(int));
	}
	
	return tab;
}

void init(int** tab, int nb_ligne, int nb_colone){
	for(int i=0;i<nb_ligne;i++){
		for(int j=0;j<nb_colone;j++){
			scanf("%d",&tab[i][j]);
		}
	}
}

void liberer(int** tab, int nb_ligne){
	for(int i =0;i<nb_ligne;i++){
			free(tab[i]);
		}
	free(tab);	
}

void afficher(int** tab, int nb_ligne, int nb_colone){
	    for(int i=0; i<nb_ligne; i++){
			printf("+");			
			for(int k=0; k<nb_colone; k++){
				printf("---+");
			}
		    	printf("\n");			
			for(int j=0; j<nb_colone; j++){				
				printf("|");
				if (tab[i][j] == 1){
					printf(" 0 ");
				}				
				else{
					printf("   ");
				}
			}
			printf("|\n");
		}
		printf("+");			
		for(int k=0; k<nb_colone; k++){
			printf("---+");
		}
		printf("\n");
}

int verifCasesAdjacentes(int** tab, int nb_ligne, int nb_colone, int ligne, int colone, int torique){
	int nbCasesAdjPleines = 0;
	if (torique){
		if (ligne == 0 && colone == 0) nbCasesAdjPleines = tab[0][0] + tab[0][1] +	tab[1][0] +	tab[1][1] +	tab[0][nb_colone-1] + tab[1][nb_colone-1] +	tab[nb_ligne-1][0] + tab[nb_ligne-1][1] + tab[nb_ligne-1][nb_colone-1];		
		else{
			if (ligne == nb_ligne-1 && colone == 0)	nbCasesAdjPleines = tab[nb_ligne-1][1] + tab[nb_ligne-2][0] + tab[nb_ligne-2][1] + tab[nb_ligne-1][nb_colone-1] + tab[nb_ligne-2][nb_colone-1] + tab[0][0] + tab[0][1] + tab[0][nb_colone-1];											
			else{
				if (ligne == 0 && colone == nb_colone-1) nbCasesAdjPleines = tab[0][nb_colone-2] + tab[1][nb_colone-2] + tab[1][nb_colone-1] + tab[nb_ligne-1][nb_colone-1] + tab[nb_ligne-1][nb_colone-2] + tab[0][0] + tab[1][0] + tab[nb_ligne-1][0];													
				else{
					if (ligne == nb_ligne-1 && colone == nb_colone-1) nbCasesAdjPleines = tab[0][0] + tab[nb_ligne-1][nb_colone-2] + tab[nb_ligne-2][nb_colone-2] + tab[nb_ligne-2][nb_colone-1] + tab[0][nb_colone-1] + tab[0][nb_ligne-2] + tab[nb_ligne-1][0] + tab[nb_ligne-2][0]; 							
					else{
						if (ligne == 0)	nbCasesAdjPleines = tab[nb_ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne+1][colone-1] + tab[nb_ligne-1][colone] + tab[ligne+1][colone] + tab[nb_ligne-1][colone+1] + tab[ligne][colone+1] + tab[ligne+1][colone+1];														
						else{
							if (ligne == nb_ligne-1) nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[0][colone-1] + tab[ligne-1][colone] + tab[0][colone] + tab[ligne-1][colone+1] + tab[ligne][colone+1] + tab[0][colone+1];													
							else{
								if (colone == 0) nbCasesAdjPleines = tab[ligne-1][nb_colone-1] + tab[ligne][nb_colone-1] + tab[ligne+1][nb_colone-1] + tab[ligne-1][colone] + tab[ligne+1][colone] + tab[ligne-1][colone+1] + tab[ligne][colone+1] + tab[ligne+1][colone+1];													
								else{
									if (colone == nb_colone-1) nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne+1][colone-1] + tab[ligne-1][colone] + tab[ligne+1][colone] + tab[ligne-1][0] + tab[ligne][0] + tab[ligne+1][0];										
									else{
										nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne+1][colone-1] + tab[ligne-1][colone] + tab[ligne+1][colone] + tab[ligne-1][colone+1] + tab[ligne][colone+1] + tab[ligne+1][colone+1];	//verif pour tout le reste
									}
								}
							}
						}
					}
				}
			}
		}
	}

	
	else{
		if (ligne == 0 && colone == 0) nbCasesAdjPleines = tab [ligne+1][colone] + tab[ligne][colone+1] + tab[ligne+1][colone+1];																															//verif si on est en haut à gauche
		else{
			if (ligne == nb_ligne-1 && colone == 0) nbCasesAdjPleines = tab [ligne-1][colone] + tab[ligne][colone+1] + tab[ligne-1][colone+1];																												//verif si on est en bas à gauche
			else{
				if (ligne == 0 && colone == nb_colone-1) nbCasesAdjPleines = tab [ligne][colone-1] + tab[ligne+1][colone-1] + tab[ligne+1][colone];																											//verif si on est en haut à droite
				else{
					if (ligne == nb_ligne-1 && colone == nb_colone-1) nbCasesAdjPleines = tab [ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne-1][colone];																							//verif si on est en bas à droite
					else{
						if (ligne == 0) nbCasesAdjPleines =tab[ligne][colone-1] + tab[ligne+1][colone-1]+ tab[ligne+1][colone] + tab[ligne][colone+1] + tab[ligne+1][colone+1];																				//verif si la case est sur la colone du haut
						else{
							if (ligne == nb_ligne-1) nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne-1][colone]+ tab[ligne-1][colone+1] + tab[ligne][colone+1];																//verif si la case est sur la colone du bas
							else{
								if (colone == 0) nbCasesAdjPleines =tab[ligne-1][colone] + tab[ligne+1][colone] + tab[ligne-1][colone+1] + tab[ligne][colone+1] + tab[ligne+1][colone+1];																	//verif si la case est sur la ligne de gauche
								else{
									if (colone == nb_colone-1) nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne+1][colone-1] + tab[ligne-1][colone] + tab[ligne+1][colone];													//verif si la case est sur la ligne de droite
									else{
										nbCasesAdjPleines = tab[ligne-1][colone-1] + tab[ligne][colone-1] + tab[ligne+1][colone-1] + tab[ligne-1][colone] + tab[ligne+1][colone] + tab[ligne-1][colone+1] + tab[ligne][colone+1] + tab[ligne+1][colone+1];	//verif pour tout le reste
									}
								}
							}
						}
					}
				}
			}
		}
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
	}else{										// Si il colone a deja un cellule
		if(nb_voisin == 3 || nb_voisin == 2){		// Si il colone a 2 ou 3 voisins
			return 1;									// La cellule reste en vie
		}else{									//Sinon
			return 0;								// La cellule meurt
		}
	}
}

void tour(int*** p_tab,int nb_ligne,int nb_colone,int torique){
	int** t_temp;
	int** tab;
	int nb_voisin;
	int valeur_case;

	t_temp = alloc(nb_ligne,nb_colone);   //allocation du tableau temporaire
	tab = *p_tab;

	// initialisation des valeur du tableau temporaire
	for(int i=0;i<nb_ligne;i++){
		for(int j=0;j<nb_colone;j++){
			nb_voisin = verifCasesAdjacentes(tab,nb_ligne,nb_colone,i,j,torique);
			valeur_case = tab[i][j];
			t_temp[i][j]= nouvellevaleur(nb_voisin,valeur_case);
		}
	}

	*p_tab = t_temp;   // le tableau prend ses nouvelles valeurs
}
