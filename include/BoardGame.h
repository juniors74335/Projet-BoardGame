


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
	int player1Score;
	int player2Score;
}Board;





int Initialize ();
void InitializeBoard(Board b);
void AddCharAtPosition(Board b, int x, int y, char toBeAdded);
void Move(Board b, int x, int y);