


#define TAILLE_MAX_JOUEUR 32




typedef struct Joueur
{
	char *Nom;
	int nbrVictoire;
}Joueur;








int Initialize ();
void InitializeBoard(Board b);
void AddCharAtPosition(Board b, int x, int y, char toBeAdded);
void Move(Board b, int x, int y);