#include "Power4.h"
#include "BoardGame.h"

void partiePower4(Joueur joueur1, Joueur joueur2)
{
  int l,c;
  int i,j;
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

  
  while(!finDePartie)
  {
  	
		afficherBoard(grilleP4);
		printf("C'est a %s de jouer : \n", joueur1.Nom);
		printf("Entrez la colonne du pion que vous souhaitez rentrer (de 1 a 8)\n");
		scanf("%d",newCol);
		while (grilleP4.tabBoard[newCol-1][7] != 219) {
			printf("Cette colonne est deja pleine, rentrez en une autre(de 1 a 8)\n");
			scanf("%d",newCol);
		}
		l = 7;
		while (grilleP4.tabBoard[newCol-1][l] == 219)
		{
			l--;
		}
		l += 1;
		c = newCol-1;
		if(tourDeJeu == 0) {	
			grilleP4.tabBoard[newCol-1][l] == 'O';
		}else if(tourDeJeu == -1) {
			grilleP4.tabBoard[newCol-1][l] == 'X';
		}
		if(newCol-1 > 0)
		{
			while(c > 0 && grilleP4.tabBoard[c][l] == '1' && puissance1 < 4)
			{
				puissance1 ++;
				c --;
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