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
			printf("C'est a %s de jouer : \n", joueur1.Nom);
			printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord ligne puis colonne)\n");
			scanf("%s",positionNouveauPion);
			positionNouveauPion[2] = 0;
			//Verif Position correcte
			while ((retourVerifPos = verifPositionOk(positionNouveauPion,leBoard,tourDeJeu)) == 0) {
				printf("Ceci n'est pas une position valide, rentrez en une autre(d'abord ligne puis colonne)\n");
				scanf("%s",positionNouveauPion);
				positionNouveauPion[2] = 0;
			}


			// Change les nombres de pions des joueurs, change la valeur pour les cases sur le board
			leBoard = updateBoard(leBoard,retourVerifPos,tourDeJeu,positionNouveauPion);
			
			//leBoard.tabBoard[positionNouveauPion[0]-97][positionNouveauPion[1]] = 'O';








			tourDeJeu = -1;
		}else {
			printf("C'est a %s de jouer : \n", joueur2.Nom);		
			printf("Entrez les coordonnes du pion que vous souhaitez rentrez (d'abord ligne puis colonne)\n");
			scanf("%s",positionNouveauPion);
			positionNouveauPion[2] = 0;
			//Verif Position correcte
			while ((retourVerifPos = verifPositionOk(positionNouveauPion,leBoard,tourDeJeu)) == 0) {
				printf("Ceci n'est pas une position valide, rentrez en une autre(d'abord ligne puis colonne)\n");
				scanf("%s",positionNouveauPion);
				positionNouveauPion[2] = 0;
			}	
			leBoard = updateBoard(leBoard,retourVerifPos,tourDeJeu,positionNouveauPion);
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
	int c = mesDeuxChar[0]-97;
	int l = mesDeuxChar[1] - 49;
	int i;
	int j;
	int retour = 0;



	if(tourDeJeu == 0) {

		// Verif Droite
		if((i = c + 1) < 8) {
			if(b.tabBoard[l][i] == 'X') {
				for(i = c + 2;i < 8;i++) {
					if(b.tabBoard[l][i] == 219) {
						i = 8;
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
						i = -1;
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
						i = -1;
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
						i = 8;
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
				if(b.tabBoard[j][i] == 'X') {
					i = c - 2;
					j = l - 2;
					while( i >= 0 && j >= 0) {
						if(b.tabBoard[i][c] == 219) {
							i = -1;
							break;
						}
						
						if(b.tabBoard[j][i] == 'O')
							retour += 10000;
						i--;
						j--;
						
					}
				}
			}
		}

		// Diago Bas Gauche

		if((i = c + 1) < 8) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[j][i] == 'X') {
					i = c + 2;
					j = l - 2;
					while( i < 8 && j >= 0) {
						if(b.tabBoard[i][c] == 219) {
							i = 8;
							break;
						}
						
						if(b.tabBoard[j][i] == 'O')
							retour += 100000;
						i++;
						j--;
						
					}
				}
			}
		}

		// Diago Haut Droite

		if((i = c - 1) >= 0) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[j][i] == 'X') {
					i = c - 2;
					j = l + 2;
					while( i >= 0 && j < 8) {
						if(b.tabBoard[i][c] == 219) {
							i = -1;
							break;
						}
						
						if(b.tabBoard[j][i] == 'O')
							retour += 1000000;
						i--;
						j++;
						
					}
					
				}
			}
		}

		// Diago Bas Droite

		if((i = c + 1) < 8) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[j][i] == 'X') {
					i = c + 2;
					j = l + 2;
					while( i < 8 && j < 8) {
						if(b.tabBoard[i][c] == 219) {
							i = 8;
							break;
						}
						
						if(b.tabBoard[j][i] == 'O')
							retour += 10000000;
						i++;
						j++;
						
					}
				}
			}
		}

		// FIn des tests...
	}else if(tourDeJeu == -1) {

		// Verif Droite
		if((i = c + 1) < 8) {
			if(b.tabBoard[l][i] == 'O') {
				for(i = c + 2;i < 8;i++) {
					if(b.tabBoard[l][i] == 219) {
						i = 8;
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
						i = -1;
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
						i = -1;
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
						i = 8;
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
				if(b.tabBoard[j][i] == 'O') {
					i = c - 2;
					j = l - 2;
					while( i >= 0 && j >= 0) {
						if(b.tabBoard[j][i] == 219) {
							i = -1;
							break;
						}
						
						if(b.tabBoard[j][i] == 'X')
							retour += 10000;
						i--;
						j--;
						
					}
				}
			}
		}

		// Diago Bas Gauche

		if((i = c + 1) < 8) {
			if((j = l -1) >= 0) {
				if(b.tabBoard[j][i] == 'O') {
					i = c + 2;
					j = l - 2;
					while( i < 8 && j >= 0) {
						if(b.tabBoard[j][i] == 219) {
							j = -1;
							break;
						}
						
						if(b.tabBoard[j][i] == 'X')
							retour += 100000;
						i++;
						j--;
						
					}
				}
			}
		}

		// Diago Haut Droite

		if((i = c - 1) >= 0) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[j][i] == 'O') {
					i = c - 2;
					j = l + 2;
					while( i >= 0 && j < 8) {
						if(b.tabBoard[j][i] == 219) {
							i = -1;
							break;
						}
						
						if(b.tabBoard[j][i] == 'X')
							retour += 1000000;
						i--;
						j++;
						
					}
					
				}
			}
		}

		// Diago Bas Droite

		if((i = c + 1) < 8) {
			if((j = l + 1) < 8) {
				if(b.tabBoard[j][i] == 'O') {
					i = c + 2;
					j = l + 2;
					while( i < 8 && j < 8) {
						if(b.tabBoard[j][i] == 219) {
							i = 8;
							break;
						}
						
						if(b.tabBoard[j][i] == 'X')
							retour += 10000000;
						i++;
						j++;
						
					}
				}
			}
		}
		// FIn des tests...
		
	}
	return retour;
}



Board updateBoard(Board b,int valeurRetour,int tourDeJeu,char* mesDeuxChar) {
	int c = mesDeuxChar[0]-97;
	int l = mesDeuxChar[1] - 49;
	int i;
	int j;
	
	if(tourDeJeu == 0) {
		b.tabBoard[l][c] = 'O';
		if(valeurRetour - 10000000 >= 0) {
			valeurRetour -= 10000000;
			i = c + 1;
			j = l + 1;
			while( i < 8 && j < 8) {
				if(b.tabBoard[j][i] == 'O') 
					i = 8;
				else
					b.tabBoard[j][i] = 'O';
				i++;
				j++;
				
			}
		}
		if(valeurRetour - 1000000 >= 0) {
			valeurRetour -= 1000000;
			i = c - 1;
			j = l + 1;
			while( i >= 0 && j < 8) {
				if(b.tabBoard[j][i] == 'O') 
					i = -1;
				else
					b.tabBoard[j][i] = 'O';
				i--;
				j++;
				
			}
		}
		printf("%d\n", valeurRetour);
		if(valeurRetour - 100000 >= 0) {
			valeurRetour -= 100000;
			i = c + 1;
			j = l - 1;
			while( i < 8 && j >= 0) {
				if(b.tabBoard[j][i] == 'O') 
					i = 8;
				else
					b.tabBoard[j][i] = 'O';
				i++;
				j--;
				
			}
		}
		if(valeurRetour - 10000 >= 0) {
			valeurRetour -= 10000;
			printf("c%dl%d\n ",c,l);
			i = c - 1;
			j = l - 1;
			while( i >= 0 && j >= 0) {
				if(b.tabBoard[j][i] == 'O') 
					i = -1;
				else
					b.tabBoard[j][i] = 'O';
				i--;
				j--;
				
			}
		}
		if(valeurRetour - 1000 >= 0) {
			valeurRetour -= 1000;
			for(i = l + 1;i < 8;i++) {
				if(b.tabBoard[i][c] == 'O') 
					i = 8;
				else
					b.tabBoard[i][c] = 'O';
				
			}
		}
		if(valeurRetour - 100 >= 0) {
			valeurRetour -= 100;
			for(i = l - 1;i >= 0;i--) {
				if(b.tabBoard[i][c] == 'O') 
					i = -1;
				else
					b.tabBoard[i][c] = 'O';
				
			}
		}
		if(valeurRetour - 10 >= 0) {
			valeurRetour -= 10;
			for(i = c - 1;i >= 0;i--) {
				if(b.tabBoard[l][i] == 'O') 
					i = -1;
				else
					b.tabBoard[l][i] = 'O';
				
			}
		}
		if((valeurRetour - 1) >= 0) {
			valeurRetour -= 1;

	
			for(i = c + 1;i < 8;i++) {
				if(b.tabBoard[l][i] == 'O') 
					i = 8;
				else
					b.tabBoard[l][i] = 'O';
				
			}
		}


	}else if(tourDeJeu == -1) {
		b.tabBoard[l][c] = 'X';
		if(valeurRetour - 10000000 >= 0) {
			valeurRetour -= 10000000;
			i = c + 1;
			j = l + 1;
			while( i < 8 && j < 8) {
				if(b.tabBoard[j][i] == 'X') 
					i = 8;
				else
					b.tabBoard[j][i] = 'X';
				i++;
				j++;
				
			}
		}
		if(valeurRetour - 1000000 >= 0) {
			valeurRetour -= 1000000;
			i = c - 1;
			j = l + 1;
			while( i >= 0 && j < 8) {
				if(b.tabBoard[j][i] == 'X') 
					i = -1;
				else
					b.tabBoard[j][i] = 'X';
				i--;
				j++;
				
			}
		}
		if(valeurRetour - 100000 >= 0) {
			valeurRetour -= 100000;
			i = c + 1;
			j = l - 1;
			while( i < 8 && j >= 0) {
				if(b.tabBoard[j][i] == 'X') 
					i = 8;
				else
					b.tabBoard[j][i] = 'X';
				i++;
				j--;
				
			}
		}
		if(valeurRetour - 10000 >= 0) {
			valeurRetour -= 10000;
			i = c - 1;
			j = l - 1;
			while( i >= 0 && j >= 0) {
				if(b.tabBoard[j][i] == 'X') 
					i = -1;
				else				
					b.tabBoard[j][i] = 'X';
				i--;
				j--;
				
			}
		}
		if(valeurRetour - 1000 >= 0) {
			valeurRetour -= 1000;
			for(i = l + 1;i < 8;i++) {
				if(b.tabBoard[i][c] == 'X') 
					i = 8;
				else
					b.tabBoard[i][c] = 'X';
				
			}

		}
		if(valeurRetour - 100 >= 0) {
			valeurRetour -= 100;
			for(i = l - 1;i >= 0;i--) {
				if(b.tabBoard[i][c] == 'X')
					i = -1;
				else 
					b.tabBoard[i][c] = 'X';
			}
		}
		if(valeurRetour - 10 >= 0) {
			valeurRetour -= 10;
			for(i = c - 1;i >= 0;i--) {
				if(b.tabBoard[l][i] == 'X') 
					i = -1;
				else
					b.tabBoard[l][i] = 'X';
			}
		}
		if(valeurRetour - 1 >= 0) {
			valeurRetour -= 1;
			for(i = c + 1;i < 8;i++) {
				if(b.tabBoard[l][i] == 'X') 
					i = 8;
				else
					b.tabBoard[l][i] = 'X';
				
			}
		}
	}
	return b;

}



