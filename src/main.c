#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#include "header.h"
#include "affichage.h"

#define N 600      //Taille fenetre

int main(int argc, char** argv){
	int nb_ligne;
	int nb_colone;
	int nb_iteration;
	int torique;
	int** tab;
	
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	
	
	
	//initialisation
	SDL_Initialisation(&window,&renderer,N);
	
	
	
	scanf("%d",&nb_ligne);
	scanf("%d",&nb_colone);
	
	tab = alloc(nb_ligne,nb_colone);    //allocation du tableau
	
	init(tab,nb_ligne,nb_colone);       // initialisation tableau
	
	
	
	scanf("%d",&nb_iteration);
	scanf("%d",&torique);
	

	for(int i =1;i<=nb_iteration;i++){
		effacer_ecran(&renderer,N);
		afficher_tableau(&renderer,N,tab,nb_ligne,nb_colone);
		SDL_RenderPresent(renderer);
		SDL_Delay(200);
		tour(&tab,nb_ligne,nb_colone,torique);
	}
	
	
	liberer(tab,nb_ligne);   // liberation memoire du tableau
	
	SDL_liberation(&window,&renderer);
	
	return 0;
}
