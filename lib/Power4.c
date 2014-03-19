#include "Power4.h"

void partiePower4()
{
  int l,c;
  l = 0;
  c = 0;
  int finDePartie = 0;
  int tourDeJeu = 0;
  int newCol;
  int puissance1 = 0;
  int puissance2 = 0;
  int totPuissance = 0;
  Board grilleP4;
  grilleP4 = InitializeBoard(grilleP4);
  grilleP4.player1Name = joueur1.Nom;
  grilleP4.player2Name = joueur2.Nom;
  grilleP4.player1Score = 2;
  grilleP4.player2Score = 2;
  for (int i = 0; i < 8; ++i)
  {
  	for (int j = 0; j < 8; ++j)
  	{
  		grilleP4.tabBoard[i][j] = '0';
  	}
  }
  while(!finDePartie)
  {
  	if(tourDeJeu == 0)
		{
			printf("C'est a %s de jouer : \n", joueur1.Nom);
			printf("Entrez la colonne du pion que vous souhaitez rentrer (de 1 a 8)\n");
			scanf("%i",newCol);
			while (grilleP4[newCol-1][7] != '0') {
				printf("Cette colonne est deja pleine, rentrez en une autre(de 1 a 8)\n");
				scanf("%i",newCol);
			}
			l = 7;
			while (grilleP4[newCol-1][l] =='0')
			{
				l --;
			}
			l = l-1;
			c = newCol-1;
			grilleP4[newCol-1][l] == '1'
			if(newCol-1 > 0)
			{
				while(c > 0 && grilleP4[c][l] == '1' && puissance1 < 4)
				{
					puissance1 ++;
					c --;
				}
				
			}




			tourDeJeu = -1;
		}else {
			printf("C'est a %s de jouer : \n", joueur2.Nom);
			printf("Entrez la colonne du pion que vous souhaitez rentrer (de 1 a 8)\n");
			scanf("%i",newCol);
			while (grilleP4[newCol-1][7] != '0') {
				printf("Cette colonne est deja pleine, rentrez en une autre(de 1 a 8)\n");
				scanf("%i",newCol);
			}
			l = 7;
			while (grilleP4[newCol-1][l] =='0')
			{
				l --;
			}
			grilleP4[newCol-1][l-1] == '2'			
			tourDeJeu = 0;
		}
  }

}