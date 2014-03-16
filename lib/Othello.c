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
	leBoard.player1Score = 2;
	leBoard.player2Score = 2;
	
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
			//Verif Position correcte
			while (verifPositionOk(positionNouveauPion,leBoard,tourDeJeu) == 0) {
				printf("Ceci n'est pas une position valide, rentrez en une autre(d'abord colonne puis ligne)\n");
				scanf("%s",positionNouveauPion);
				positionNouveauPion[2] = 0;
			}



			// Change les nombres de pions des joueurs, change la valeur pour les cases sur le board
			
			
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
	b.tabBoard[3][4] = 'O';
    b.tabBoard[4][3] = 'O';
 
    b.tabBoard[4][4] = 'X';
    b.tabBoard[3][3] = 'X';
    return b;
}


int verifPositionOk(char* mesDeuxChar,Board b,int tourDeJeu) {


}