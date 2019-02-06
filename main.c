/* Notes à moi même (et autre chieuse ou rouquin du groupe) :
 * Peut-être faire une structure pièce pour décompter le nombre de pièces utilisées, afficher une pièce, connaitre la valeur numérique de la piece.
 */

#include <stdlib.h>
#include <stdio.h>

#define L 7 /*Lignes*/
#define C 7 /*Colonnes*/
#define N 7 /* Nombre dsiponnible de chaque type de pièce */


typedef struct piece_s {
    int nb_piece; /*Compteur*/
    char couleur; /*Jaune ou rouge*/
    int valeur; /*Pleine,creuse,bloquantes*/
}piece_t;


/* Initialisation de la grille */
void init_grille(char grille[L][C]){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            grille[i][j] = ' ';
    }
}

/*Affichage de la grille */
void afficher_grille(char grille[L][C]){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            printf("%c |", grille[i][j]);
        printf("\n");            
    }
}

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
*/
int nonPleine(piece_t piece, int nbCol, int * pos, char grille[L][C]){

    switch(piece.valeur){
        /* Cas 1 et 2 à ajuster en fonctions des règles (j'ai oublié entre creuses et pleines, qui bloque qui) */
        case 1 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        pos = i;
                        return 1;
                    }
                }
                break;
        case 2 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        pos = i;
                        return 1;
                    }
                }
                break;
        /* Cas 3 OK */
        case 3 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        pos = i;
                        return 1;
                    }
                }
                break;
    }
    return -1;
}

/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
void tour_joueur(int nJoueur, char grille[L][C]){
    int col, pos;
    
    piece_t piece;
    piece.nb_piece = N;
    if(nJoueur) piece.couleur = 'jaune';
    else piece.couleur = 'rouge';

    /*Affecter la couleur de la pièce en fonction du choix du type de la pièce
    * /!\/!\/!\/!\/!\/!\
    */
    

    /* Demande de saisie de la piece. Penser à vérifier que piece est un entier plus tard.
     * Il faudrat aussi prendre en compte le nombre disponible de chaque piece pour la suite.
    */
    printf("Choix du type de pièce à jouer : \n");
    printf("1- Pleine \n");
    printf("2- Creuse \n");
    printf("3- Bloquante \n");
    do{
        printf("Choix : ");
        scanf("%d", &piece.valeur);
    }while(piece.valeur > 0 && piece.valeur < 4);

    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et 7): ");
        scanf("%d", &col);
    }while(nonPleine(piece, col, &pos, grille) && col > 0 && col < 8);

    /* Ajout de la piece et mise à jour de la piece*/
    switch(piece.valeur){
        case 1: if(nbJoueur == 1) grille[pos][col] = 'P';
                else grille[pos][col] = 'p';

                break;
        case 2: if(nbJoueur == 1) grille[pos][col] = 'C';
                else grille[pos][col] = 'c';
                break;
        case 3: if(nbJoueur == 1) grille[pos][col] = 'B';
                else grille[pos][col] = 'b';
                break;
    }
     

}

/* Fonction contenant la boucle principale du mode de jeu jVj.
*/
void joueurVSjoueur(char grille[L][C]){
    //while();
}

/*
void joueurVSia(char grille[L][C]){

}*/

int main(){

    char grille[L][C];
    int choix;
    
    printf("Selectionnez le mode de jeu : \n");
    printf("1- Joueur vs IA \n");
    printf("2- Joueur vs Joueur \n");
    printf("3- Quitter \n");

    printf("\n\n Choix : ");
    scanf("%d", &choix);

    /*
    switch(choix){
        case 1 : joueurVSia(grille);
                break;
        case 2 : joueurVSjoueur(grille);
                break;
        case 3 :
                break;
    }*/

    return 0;
}

