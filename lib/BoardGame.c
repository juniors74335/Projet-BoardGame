#include "BoardGame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Othello.h"


Joueur* joueur1 = NULL;
Joueur* joueur2 = NULL;



int main() 	{
	Initialize();
	partie(*joueur1,*joueur2);
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
	char uneCase;
	int l, c;

	for (l=0; l<8; l++)
    	{
        	for (c=0; c<8; c++)
        	{
            		b.tabBoard[l][c] = uneCase;
        	}
    	}
 
 
}

void AddCharAtPosition(Board b, int x, int y, char toBedAdded)
{

}

void Move(Board b, int x, int y)
{

}



// Fonction pour afficher tout le board a l'ecran.
void afficherBoard(Board b) 
{
	int l,c;
    	c=1;
     	char lettre;
   	for (lettre='a'; lettre<='h'; lettre++) // Affichage des lettres
        {
        	printf ("%c", lettre);
        }
	
}