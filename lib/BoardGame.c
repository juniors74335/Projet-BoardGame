#include "BoardGame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Joueur* joueur1 = NULL;
Joueur* joueur2 = NULL;



int main() 	{
	Initialize();
	return 0;

}










/*
	Initialise mes deux joueurs
	retourne 0 si les deux joueurs ont bien été créer,
	retourne -1 si les l'un des deux joueurs n'est pas initialisé ou 1
	retourne -2 si erreurs inconnue...
*/
int Initialize (){
	char unString[TAILLE_MAX_JOUEUR];
	if(joueur1 == NULL)
	{
		joueur1 = (Joueur*) malloc(sizeof(Joueur));
		printf("Veuillez entrez le nom du joueur 1 :\n");
		scanf("%s",unString);
		joueur1->Nom = unString;
		joueur1->nbrVictoire = 0;
	}
	if(joueur2 == NULL)
	{
		joueur2 = (Joueur*) malloc(sizeof(Joueur));
		printf("Veuillez entrez le nom du joueur 2 :\n");
		scanf("%s",unString);
		joueur2->Nom = unString;
		joueur2->nbrVictoire = 0;
	}
	if(joueur2 != NULL && joueur1 != NULL)
	{

		return 0;
	}else {
		return -1;
	}
	return -2;
}

void InitializeBoard(Board b)
{
	int i,j;
	for (i=0; i<8; i++)
    	{
        	for (j=0; i<8; j++)
        	{
            		(*Board).tabBoard[i][j] =0;
        	}
    	}
	int l, c;
 
    for (l=0; l<8; l++)
    {
        for (c=0; c<8; c++)
        {
            (*Board).tabBoard[l][c] = VIDE;
        }
    }
 
    // On place les 4 premiers pions pour le début de la partie
 
    (*Board).tabBoard[T/2-1][T/2] = BLANC;
    (*Board).tabBoard[T/2][T/2-1] = BLANC;
 
    (*Board).tabBoard[T/2][T/2] = NOIR;
    (*Board).tabBoard[T/2-1][T/2-1] = NOIR;
}

void AddCharAtPosition(Board b, int x, int y, char toBedAdded)
{

}

void Move(Board b, int x, int y)
{

}