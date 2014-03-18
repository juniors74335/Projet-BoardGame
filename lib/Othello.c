#include "BoardGame.h"
#include "stdio.h"
#include "Othello.h"
#include "stdlib.h"


void partie(Joueur joueur1,Joueur joueur2) {
	Board leBoard;
	int finDePartie = 0;
	int tourDeJeu = 0;					// tour de jeu a 0 = joueur1;
	char positionNouveauPion[3];
	int retourVerifPos;

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
			printf("\nC'est a %s de jouer:\n",&(leBoard.player1Name));
			printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord colonne puis ligne)\n");



			scanf("%s",positionNouveauPion);
			positionNouveauPion[2] = 0;
			//Verif Position correcte
			while ((retourVerifPos = verifPositionOk(positionNouveauPion,leBoard,tourDeJeu)) == 0) {
				// Debug

				printf("Position rentre %c %c\n",positionNouveauPion[0],positionNouveauPion[1] );


				printf("Ceci n'est pas une position valide, rentrez en une autre(d'abord colonne puis ligne)\n");
				scanf("%s",positionNouveauPion);
				positionNouveauPion[2] = 0;
			}


			// Change les nombres de pions des joueurs, change la valeur pour les cases sur le board
			updateBoard(leBoard,retourVerifPos);
			
			//leBoard.tabBoard[positionNouveauPion[0]-97][positionNouveauPion[1]] = 'O';








			tourDeJeu = -1;
		}else {
			printf("\nC'est a %s de jouer:\n",&(leBoard.player2Name));		
			printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord colonne puis ligne)\n");



			scanf("%s",positionNouveauPion);
			positionNouveauPion[2] = 0;
			//Verif Position correcte
			while ((retourVerifPos = verifPositionOk(positionNouveauPion,leBoard,tourDeJeu)) == 0) {
				// Debug

				printf("Position rentre %c %c\n",positionNouveauPion[0],positionNouveauPion[1] );


				printf("Ceci n'est pas une position valide, rentrez en une autre(d'abord colonne puis ligne)\n");
				scanf("%s",positionNouveauPion);
				positionNouveauPion[2] = 0;
			}	
			tourDeJeu = 0;
		}

		






		// quand fin de partie?
		//finDePartie = -1;
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
	int l = mesDeuxChar[0]-97;
	int c = mesDeuxChar[1] - 49;
	int i;
	int j;
	int retour = 0;

	// Debug

	printf("valeur l et c %d %d\n",l,c);


	if(tourDeJeu == 0) {

		// Verif Droite
		if((i = c + 1) < 8) {
			if(b.tabBoard[l][i] == 'X') {
				for(i = c + 2;i < 8;i++) {
					if(b.tabBoard[l][i] == 219) {
						break;
					}
					if(b.tabBoard[l][i] == 'O') {
						retour += 1;
					}
				}
			}
		}
		

		// Verif Gauche
		if((i = c - 1) >= 0) {
			if(b.tabBoard[l][i] == 'X') {
				for(i = c - 2;i >= 0;i--) {
					if(b.tabBoard[l][i] == 219) {
						break;
					}
					if(b.tabBoard[l][i] == 'O') {
						retour += 10;
					}
				}
			}
		}


		// Verif haut
		if((i = l - 1) >= 0) {
			if(b.tabBoard[i][c] == 'X') {
				for(i = l - 2;i >= 0;i--) {
					if(b.tabBoard[i][c] == 219) {
						break;
					}
					if(b.tabBoard[i][c] == 'O') {
						retour += 100;
					}
				}
			}
		}


		// Verif bas

		if((i = l + 1) < 8) {
			if(b.tabBoard[i][c] == 'X') {
				for(i = l + 2;i < 8;i++) {
					if(b.tabBoard[i][c] == 219) {
						break;
					}
					if(b.tabBoard[i][c] == 'O') {
						retour += 1000;
					}
				}
			}
		}

		// Verif 4 diago
		// Diago  Haut Gauche
		if((i = c - 1) >= 0) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[i][j] == 'X') {
					for(i = c - 2; i >= 0;i--) {
						for(j = l - 2;j >= 0; j--) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'O')
								retour += 10000;
						}
					}
				}
			}
		}

		// Diago Bas Gauche

		if((i = c + 1) < 8) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[i][j] == 'X') {
					for(i = c + 2; i < 8;i++) {
						for(j = l - 2;j >= 0; j--) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'O')
								retour += 100000;
						}
					}
				}
			}
		}

		// Diago Haut Droite

		if((i = c - 1) >= 0) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[i][j] == 'X') {
					for(i = c - 2; i >= 0;i--) {
						for(j = l + 2;j < 8; j++) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'O')
								retour += 1000000;
						}
					}
				}
			}
		}

		// Diago Bas Droite

		if((i = c + 1) < 8) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[i][j] == 'X') {
					for(i = c + 2; i < 8;i++) {
						for(j = l + 2;j < 8; j++) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'O')
								retour += 10000000;
						}
					}
				}
			}
		}


		// Debug


		// FIn des tests...
	}else if(tourDeJeu == 0) {

		// Verif Droite
		if((i = c + 1) < 8) {
			if(b.tabBoard[l][i] == 'O') {
				for(i = c + 2;i < 8;i++) {
					if(b.tabBoard[l][i] == 219) {
						break;
					}
					if(b.tabBoard[l][i] == 'X') {
						retour += 1;
					}
				}
			}
		}
		

		// Verif Gauche
		if((i = c - 1) >= 0) {
			if(b.tabBoard[l][i] == 'O') {
				for(i = c - 2;i >= 0;i--) {
					if(b.tabBoard[l][i] == 219) {
						break;
					}
					if(b.tabBoard[l][i] == 'X') {
						retour += 10;
					}
				}
			}
		}


		// Verif haut
		if((i = l - 1) >= 0) {
			if(b.tabBoard[i][c] == 'O') {
				for(i = l - 2;i >= 0;i--) {
					if(b.tabBoard[i][c] == 219) {
						break;
					}
					if(b.tabBoard[i][c] == 'X') {
						retour += 100;
					}
				}
			}
		}


		// Verif bas

		if((i = l + 1) < 8) {
			if(b.tabBoard[i][c] == 'O') {
				for(i = l + 2;i < 8;i++) {
					if(b.tabBoard[i][c] == 219) {
						break;
					}
					if(b.tabBoard[i][c] == 'X') {
						retour += 1000;
					}
				}
			}
		}

		// Verif 4 diago
		// Diago  Haut Gauche
		if((i = c - 1) >= 0) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[i][j] == 'O') {
					for(i = c - 2; i >= 0;i--) {
						for(j = l - 2;j >= 0; j--) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'X')
								retour += 10000;
						}
					}
				}
			}
		}

		// Diago Bas Gauche

		if((i = c + 1) < 8) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[i][j] == 'O') {
					for(i = c + 2; i < 8;i++) {
						for(j = l - 2;j >= 0; j--) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'X')
								retour += 100000;
						}
					}
				}
			}
		}

		// Diago Haut Droite

		if((i = c - 1) >= 0) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[i][j] == 'O') {
					for(i = c - 2; i >= 0;i--) {
						for(j = l + 2;j < 8; j++) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'X')
								retour += 1000000;
						}
					}
				}
			}
		}

		// Diago Bas Droite

		if((i = c + 1) < 8) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[i][j] == 'O') {
					for(i = c + 2; i < 8;i++) {
						for(j = l + 2;j < 8; j++) {
							if(b.tabBoard[i][j] == 219) {
								break;
							}
							if(b.tabBoard[i][j] == 'X')
								retour += 10000000;
						}
					}
				}
			}
		}


		// Debug


		// FIn des tests...
		
	}
	return retour;
}



void updateBoard(Board b,int retour) {


}



