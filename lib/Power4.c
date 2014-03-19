#include "Power4.h"
#include "BoardGame.h"
#include "stdio.h"
#include "stdlib.h"

void partiePower4(Joueur joueur1, Joueur joueur2)
{
  int l,c;
  int i,j;
  l = 0;
  c = 0;
  int finDePartie = 0;
  int tourDeJeu = 0;
  char newCol[2];
  int Col;
  int victoire =0;
  Board grilleP4;

  grilleP4 = InitializeBoard(grilleP4);

  
  while(!finDePartie)
  {
  	
		afficherBoard(grilleP4);
		if(tourDeJeu == 0) {
			printf("C'est a %s de jouer : \n", joueur1.Nom);
		}else {
			printf("C'est a %s de jouer : \n", joueur2.Nom);
		}
		
		printf("Entrez la colonne du pion que vous souhaitez rentrer (de 1 a 8)\n");
		scanf("%s",&newCol);
		Col = newCol[0]-49;
		while (grilleP4.tabBoard[Col][0] == 'O' || grilleP4.tabBoard[Col][0] == 'X') {
			printf("Cette colonne est deja pleine, rentrez en une autre(de 1 a 8)\n");
			scanf("%s",&newCol);
		}
		l = 0;
		while (l < 8)
		{
			if(grilleP4.tabBoard[Col][l] == 'O' || grilleP4.tabBoard[Col][l] == 'X') {
				printf("%d  ",l);
				printf("%d\n",Col);
				break;
			}
			l++;
		}
		l--;
		if(tourDeJeu == 0) {	
			grilleP4.tabBoard[Col][l] = 'O';
		}else if(tourDeJeu == -1) {
			grilleP4.tabBoard[Col][l] = 'X';
		}
		
		//Verif Victoire

		// Verif haut et bas
		if ( tourDeJeu == 0) {
			i =1;
			victoire = 1;
			while ( i + Col < 8) {
				if(grilleP4.tabBoard[Col+i][l] == 'O') {
					victoire += 1;
				}else {
					i = 8;
				}
				i++;
			}
			i = -1;
			while ( i + Col >= 0) {
				if(grilleP4.tabBoard[Col+i][l] == 'O') {
					victoire += 1;
				}else {
					i = -9;
				}
				i--;
			}
			if(victoire>=4) {
				printf("Bravo, %s a gagne !\n", joueur1.Nom);
				finDePartie = -1;
			}else {
				i = 1;
				victoire = 1;
				while ( i + l < 8) {
					if(grilleP4.tabBoard[Col][l+i] == 'O') {
						victoire += 1;
					}else {
						i = 8;
					}
					i++;
				}
				i = -1;
				while ( i + l >= 0) {
					if(grilleP4.tabBoard[Col][l+i] == 'O') {
						victoire += 1;
					}else {
						i = -9;
					}
					i--;
				}
				if(victoire>=4) {
					printf("Bravo, %s a gagne !\n", joueur1.Nom);
					finDePartie = -1;
				}else {
					i = 1;
					j = 1;
					victoire = 1;
					while ( i + l < 8 && j +Col < 8) {
						if(grilleP4.tabBoard[Col+j][l+i] == 'O') {
							victoire += 1;
						}else {
							i = 8;
						}
						i++;
						j++;
					}
					i = -1;
					j = -1;
					while ( i + l >= 0 && j + Col >= 0) {
						if(grilleP4.tabBoard[Col+j][l+i] == 'O') {
							victoire += 1;
						}else {
							i = -9;
						}
						i--;
						j--;
					}
					if(victoire>=4) {
						printf("Bravo, %s a gagne !\n", joueur1.Nom);
						finDePartie = -1;						
					}else {
						i = -1;
						j = 1;
						victoire = 1;
						while ( i + l >=0 && j +Col < 8) {
							if(grilleP4.tabBoard[Col+j][l+i] == 'O') {
								victoire += 1;
							}else {
								i = -9;
							}
							i--;
							j++;
						}
						i = 1;
						j = -1;
						while ( i + l < 8 && j + Col >=0) {
							if(grilleP4.tabBoard[Col+j][l+i] == 'O') {
								victoire += 1;
							}else {
								i = 8;
							}
							i++;
							j--;
						}
						if(victoire>=4) {
							printf("Bravo, %s a gagne !\n", joueur1.Nom);
							finDePartie = -1;
						}
					}
				}
			}

		}else {
			i =1;
			victoire = 1;
			while ( i + Col < 8) {
				if(grilleP4.tabBoard[Col+i][l] == 'X') {
					victoire += 1;
				}else {
					i = 8;
				}
				i++;
			}
			i = -1;
			while ( i + Col >= 0) {
				if(grilleP4.tabBoard[Col+i][l] == 'X') {
					victoire += 1;
				}else {
					i = -9;
				}
				i--;
			}
			if(victoire>=4) {
				printf("Bravo, %s a gagne !\n", joueur1.Nom);
				finDePartie = -1;
			}else {
				i = 1;
				victoire = 1;
				while ( i + l < 8) {
					if(grilleP4.tabBoard[Col][l+i] == 'X') {
						victoire += 1;
					}else {
						i = 8;
					}
					i++;
				}
				i = -1;
				while ( i + l >= 0) {
					if(grilleP4.tabBoard[Col][l+i] == 'X') {
						victoire += 1;
					}else {
						i = -9;
					}
					i--;
				}
				if(victoire>=4) {
					printf("Bravo, %s a gagne !\n", joueur1.Nom);
					finDePartie = -1;
				}else {
					i = 1;
					j = 1;
					victoire = 1;
					while ( i + l < 8 && j +Col < 8) {
						if(grilleP4.tabBoard[Col+j][l+i] == 'X') {
							victoire += 1;
						}else {
							i = 8;
						}
						i++;
						j++;
					}
					i = -1;
					j = -1;
					while ( i + l >= 0 && j + Col >= 0) {
						if(grilleP4.tabBoard[Col+j][l+i] == 'X') {
							victoire += 1;
						}else {
							i = -9;
						}
						i--;
						j--;
					}
					if(victoire>=4) {
						printf("Bravo, %s a gagne !\n", joueur1.Nom);
						finDePartie = -1;
					}else {
						i = -1;
						j = 1;
						victoire = 1;
						while ( i + l >=0 && j +Col < 8) {
							if(grilleP4.tabBoard[Col+j][l+i] == 'X') {
								victoire += 1;
							}else {
								i = -9;
							}
							i--;
							j++;
						}
						i = 1;
						j = -1;
						while ( i + l < 8 && j + Col >= 0) {
							if(grilleP4.tabBoard[Col+j][l+i] == 'X') {
								victoire += 1;
							}else {
								i = 8;
							}
							i++;
							j--;
						}
						if(victoire>=4) {
							printf("Bravo, %s a gagne !\n", joueur1.Nom);
							finDePartie = -1;
						}
					}
				}
			}		
		}
		
	
	

		if(tourDeJeu == 0) {
			tourDeJeu = -1;

		}else {
			tourDeJeu = 0;
		}

	
	}



  // Fin de ma fonction
}