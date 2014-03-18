#ifndef OTHELLO_H
#define OTHELLO_H

#include "BoardGame.h"




int verifPositionOk(char* mesDeuxChar,Board b,int tourDeJeu);

Board InitializeBoardOthello(Board b);

void partie(Joueur joueur1,Joueur joueur2);

void updateBoard(Board b,int valeurRetour,int tourDeJeu,int positionNouveauPion);

#endif