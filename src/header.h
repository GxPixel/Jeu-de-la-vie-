#ifndef HEADER_H
#define HEADER_H

/* Nom : Faucher Noé
 * Date : 28/04/2021 12:22
 * 
 * Allocation du tableau
 * Prends le nombres de ligne et de colone
 */
int** alloc(int nb_ligne, int nb_colone);

/* Nom : Faucher Noé
 * Date : 28/04/2021 12:30
 * 
 * Initialisation du tableau
 */
void init(int** tab, int nb_ligne, int nb_colone);

/* Nom : Faucher Noé
 * Date : 01/05/2021 18:44
 * 
 * Libere l'espace alloué au tableau
 * Prends le tableau, le nombres de ligne et de colone
 */
void liberer(int** tab, int nb_ligne);

/*  Nom : Hennuy Baptiste
 *	Date : 29/04/2021 14:26
 *	
 *	Affiche la grille
 */
void afficher(int** tab, int nb_ligne, int nb_colone);

/*	Nom : Hennuy Baptiste
 *	Date : 30/04/2021	17:30 
 *
 *	Vérifie les cases adjacentes d'une certaine case et retourne le nombre de cases pleines adjacentes
 *	Paramètres d'entrée: tableau de pointeurs,nombre de ligne ,nombre de colone , ligne de la case à vérifier, colone de la case à vérifier, grille torique (0 = non torique, 1 = torique)
 */
int verifCasesAdjacentes(int** tab, int nb_ligne, int nb_colone, int ligne, int colone, int torique);


/* Nom : FURGER Achille
 * Date : 02/05/2021 21:45
 * 
 * Retourne nouvelle valeur de la case, 
 * determinée par la règle du jeu
 */
int nouvellevaleur(int nb_voisin,int valeur_case);

/* Nom : Faucher Noé
 * Date : 03/05/2021 09:52
 * 
 *  modifie le tableau après une iteration de jeu
 *  prend le pointeur du tableau,son nombre de ligne et de colone , si il est torique ou non 
 *  (torique = 1 ; non torique =0)
 */
void tour(int*** p_tab,int nb_ligne,int nb_colone,int torique);
#endif
