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
	
	int tps_act = 0;
	int tps_pre = 0;

	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Event event;

	//initialisation
	SDL_Initialisation(&window,&renderer,N);
	
	
	
	scanf("%d",&nb_ligne);
	scanf("%d",&nb_colone);
	
	tab = alloc(nb_ligne,nb_colone);    //allocation du tableau
	
	init(tab,nb_ligne,nb_colone);       // initialisation tableau
	
	
	
	scanf("%d",&nb_iteration);
	scanf("%d",&torique);
	


	int i =1;
	while(i<=nb_iteration){
		SDL_PollEvent(&event);

		switch(event.type){

			case SDL_QUIT:
				i = nb_iteration + 1;
				break;

			default :
				tps_act = SDL_GetTicks();
				if(tps_act - tps_pre > 200){
					effacer_ecran(&renderer,N);
					afficher_tableau(&renderer,N,tab,nb_ligne,nb_colone);
					SDL_RenderPresent(renderer);
					tour(&tab,nb_ligne,nb_colone,torique);
					i++;
					tps_pre = tps_act;
				}
				break;
		}


		

	
	}
	
	
	liberer(tab,nb_ligne);   // liberation memoire du tableau
	
	SDL_liberation(&window,&renderer);
	
	return 0;
}
