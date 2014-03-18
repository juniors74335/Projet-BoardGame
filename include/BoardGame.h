#ifndef BOARDGAME_H
#define BOARDGAME_H


#define TAILLE_MAX_JOUEUR 32




typedef struct Joueur
{
	char *Nom;
	int nbrVictoire;
}Joueur;


typedef struct board
{
	char tabBoard[8][8];
	char* player1Name;
	char* player2Name;
	int TourDeJeu;
	int player1Score;			// Un peu une redite ca nan?
	int player2Score;			// Un peu une redite ca nan?
}Board;





int Initialize ();
Board InitializeBoard(Board b);					
void AddCharAtPosition(Board b, int x, int y, char toBeAdded);
void Move(Board b, int x, int y);
void afficherBoard(Board b);
void f_purge(void);



#endif