#include <SDL.h>
#include "affichage.h"

void SDL_ExitWithError(char* message){
	SDL_Log("ERREUR : %s > %s \n",message ,SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void SDL_Initialisation(SDL_Window** p_window ,SDL_Renderer** p_renderer, int taille){
	if((SDL_Init(SDL_INIT_VIDEO))!=0){SDL_ExitWithError("Initialisation SDL");}
	
	if(SDL_CreateWindowAndRenderer(taille,taille,0,p_window,p_renderer) !=0){SDL_ExitWithError("Impossible de créer la fenetre et le rendu");}
}

void SDL_liberation(SDL_Window** p_window ,SDL_Renderer** p_renderer){
	SDL_DestroyRenderer(*p_renderer);
	SDL_DestroyWindow(*p_window);
	SDL_Quit();
}

void afficher_tableau(SDL_Renderer** p_renderer , int taille, int** tab, int nb_ligne, int nb_colone){
	int taille_ligne;
	
	taille_ligne = taille/nb_ligne ;
	
	if(SDL_SetRenderDrawColor(*p_renderer,250,250,250,SDL_ALPHA_OPAQUE) !=0){SDL_ExitWithError("Impossible de changer couleur");}
	
	for(int i=0;i<nb_ligne;i++){
		for(int j=0;j<nb_colone;j++){
			if(tab[i][j]==1){
				SDL_Rect rectangle;
				rectangle.x = j * taille_ligne;
				rectangle.y = i * taille_ligne;
				rectangle.w = taille_ligne;
				rectangle.h = taille_ligne;
				
				if(SDL_RenderFillRect(*p_renderer,&rectangle)!=0){SDL_ExitWithError("imposible de dessiner un rectangle");}
			}
		}
	}
}
	
void effacer_ecran(SDL_Renderer** p_renderer , int taille){
	if(SDL_SetRenderDrawColor(*p_renderer,0,0,0,SDL_ALPHA_OPAQUE) !=0){SDL_ExitWithError("Impossible de changer couleur");}
	SDL_Rect rectangle;
	rectangle.x = 0;
	rectangle.y = 0;
	rectangle.w = taille;
	rectangle.h = taille;
				
	if(SDL_RenderFillRect(*p_renderer,&rectangle)!=0){SDL_ExitWithError("imposible de dessiner un rectangle");}
	
}
	
