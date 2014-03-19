#include "BoardGame.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Othello.h"
#include "FindTheExit.h"


Joueur* joueur1 = NULL;
Joueur* joueur2 = NULL;



int main() 	{
	int retour = 0;


	
	Initialize();
	printf("Bonjour et bienvenue sur l'application BoardGame\n");
	printf("Si vous voulez jouer a l'Othello tapez 1\n");
	printf("Si vous voulez jouer a FindTheExit, tapez 2\n");
	printf("Si vous voulez jouer au Puissance 4, tapez 3\n");

	scanf("%d",&retour);
	while(retour != 2 && retour != 1 && retour != 3) {
		scanf("%d",&retour);
	}
	if(retour == 1) {
		partie(*joueur1,*joueur2);
	}else if(retour == 2) {
		partieFindTheExit();
	}else if(retour == 3) {
		partiePower4(*joueur1, *joueur2);
	}



	
	return 0;

}


void f_purge()
{
    int c;
 
    while ((c = getchar()) != '\n' && c != EOF)
        {
        }
}







/*
	Initialise mes deux joueurs
	retourne 0 si les deux joueurs ont bien été créer,
	retourne -1 si les l'un des deux joueurs n'est pas initialisé ou 1
	retourne -2 si erreurs inconnue...
*/
int Initialize (){
	char* unString;
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

Board InitializeBoard(Board b)
{

	int l, c;

	for (l=0; l<8; l++)
    	{
        	for (c=0; c<8; c++)
        	{
            		b.tabBoard[l][c] = 219;
        	}
    	}
 	return b;
 
}

void AddCharAtPosition(Board b, int x, int y, char toBedAdded)
{
	
}

void Move(Board b, int x, int y)
{
	int l, c;
	for (l=0; l<8; l++)
    {
       	for (c=0; c<8; c++)
       	{
       		if ((c == x && l == y) && b.tabBoard[l][c] == '2')
       		{
       			printf("Erreur le pion est déja sur cette case.");
       		}
      		else if (c == x && l == y) 
      		{
      			b.tabBoard[l][c] = '2';
      		}
      		else if (b.tabBoard[l][c] == '2')
      		{
      			b.tabBoard[l][c] = '1';
      		}
       	}
    }
}



// Fonction pour afficher tout le board a l'ecran.
void afficherBoard(Board b) 
{
	int l,c;
    	
 	int lettre;

 	c=0;
 	l = 0;
   	printf("  1 2 3 4 5 6 7 8\n");

   	// A mettre dans un while qui change le a en b puis en c... a chaque fois 
   	// Pour pas te faire chier
	
   	
   		//printf(" %c", b.tabBoard[l][c]);
		for (lettre = 97; lettre <=104;lettre++)
		{
			printf("%c", lettre);
			for(l = 0;l<=7;l++) 
   			{
   				printf(" %c",b.tabBoard[l][c]);
   			}
   			printf("\n");
   			c++;
		}
   	
   	return;
}