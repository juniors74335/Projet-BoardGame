#include "BoardGame.h"
#include "stdio.h"
#include "Othello.h"


void partie(Joueur joueur1,Joueur joueur2) {
	Board leBoard;
	int finDePartie = 0;
	int tourDeJeu = 0;					// tour de jeu a 0 = joueur1;
	char positionNouveauPion[3];


	leBoard  = InitializeBoard(leBoard);
	leBoard.player1Name = joueur1.Nom;
	leBoard.player2Name = joueur2.Nom;
	
	leBoard = InitializeBoardOthello(leBoard);
	while (!finDePartie) {

		afficherBoard(leBoard);


		///// Tour de jeu du joueur1
		if(tourDeJeu == 0)
		{
			printf("\nC'est a %s de jouer:\n",leBoard.player1Name);
			printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord colonne puis ligne)\n");
			scanf("%s",positionNouveauPion);

			
			positionNouveauPion[2] = 0;
			leBoard.tabBoard[positionNouveauPion[0]-97][positionNouveauPion[1]] = 'O';
			tourDeJeu = -1;
		}else {
			tourDeJeu = 0;
			printf("\nC'est a %s de jouer:\n",leBoard.player2Name);
		}
		
		






		
		finDePartie = -1;
	}



	

}

Board InitializeBoardOthello(Board b)
{
	b.tabBoard[3][4] = 79;
    b.tabBoard[4][3] = 79;
 
    b.tabBoard[4][4] = 88;
    b.tabBoard[3][3] = 88;
    return b;
}
