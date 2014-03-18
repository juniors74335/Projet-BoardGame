#ifndef OTHELLO_H
#define OTHELLO_H

#include "BoardGame.h"




int verifPositionOk(char* mesDeuxChar,Board b,int tourDeJeu);

Board InitializeBoardOthello(Board b);

void partie(Joueur joueur1,Joueur joueur2);

Board updateBoard(Board b,int valeurRetour,int tourDeJeu,char* positionNouveauPion);

#endif