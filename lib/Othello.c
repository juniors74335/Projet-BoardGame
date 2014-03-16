#include "BoardGame.h"
#include "stdio.h"


void partie(Joueur joueur1,Joueur joueur2) {
	Board leBoard;
	int finDePartie = 0;
	int tourDeJeu = 0;					// tour de jeu a 0 = joueur1;
	char positionNouveauPion[3];


	leBoard  = InitializeBoard(leBoard);
	leBoard.player1Name = joueur1.Nom;
	leBoard.player2Name = joueur2.Nom;
	

	while (!finDePartie) {
		afficherBoard(leBoard);
		if(tourDeJeu == 0)
		{
			printf("\nC'est a %s de jouer:\n",leBoard.player1Name);

			tourDeJeu = -1;
		}else {
			tourDeJeu = 0;printf("\nC'est a %s de jouer:\n",leBoard.player2Name);
		}
		printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord colonne puis ligne)\n");
		scanf("%s",positionNouveauPion);
		positionNouveauPion[2] = 0;
		leBoard.tabBoard[positionNouveauPion[0]-97][positionNouveauPion[1]] = 'O';
		
		
		finDePartie = -1;
	}



	

}

void InitializeBoardOthello(Board b)
{
	b.tabBoard[8/2-1][8/2] = "O";
    	b.tabBoard[8/2][8/2-1] = "O";
 
    	b.tabBoard[8/2][8/2] = "X";
    	b.tabBoard[8/2-1][8/2-1] = "X";
}
