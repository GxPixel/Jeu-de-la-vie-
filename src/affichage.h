#ifndef	AFFICHAGE_H
#define AFFICHAGE_H

void SDL_ExitWithError(char* message);

void SDL_Initialisation(SDL_Window** p_window ,SDL_Renderer** p_renderer, int taille);

void SDL_liberation(SDL_Window** p_window ,SDL_Renderer** p_renderer);

void afficher_tableau(SDL_Renderer** p_renderer , int taille, int** tab, int nb_ligne, int nb_colone);

void effacer_ecran(SDL_Renderer** p_renderer , int taille);
#endif
