Projet-BoardGame
================

Devoir en C partager avec des bolosses qui foutent rien... :D



Voici les consignes :



Bonjour,
 
pour le 19 mars au plus tard, envoyez-moi un mail avec en pièce jointe une archive au nom du ou des personnes ayant travaillées sur le projet. Ce projet est à faire seul ou à deux.
 
On souhaite écrire une bibliothèque de code réutilisable pour réaliser différents jeux de plateau tels que les échecs ou l'Othello. Cette bibliothèque sera utilisée pour différents jeux très simples, appelables depuis un menu utilisateur. 
 
1)      Créer un fichier BoardGame.h dans le répertoire Include, BoardGame.c dans le répertoire lib, FindtheExit.c dans le répertoire lib et Othello.c dans le répertoire lib. Chacun de ces trois fichiers devra inclure BoardGame.h.
Tout en respectant les précautions d'usages vues en cours, écrire BoardGame.h de façon à ce qu'il contienne toutes les déclarations communes aux deux jeux, et BoardGame.c de façon à ce qu'il contienne toutes les fonctions déclarées dans le .h

 2)      Ajouter une structure board contenant un tableau de char à deux dimensions de tailles 8 et 8, deux char* destinés à contenir les noms de chaque joueur et un entier TourDeJeu et deux entiers représentant les scores de chaque joueur (pour les jeux où cette notion a un sens). Définir Board un alias vers un pointeur sur board. 

3)      Déclarer dans le .h au minimum les fonctions suivantes : void InitializeBoard(Board b), void AddCharAtPosition(Board b, int x, int y, char toBeAdded), void Move(Board b, int x, int y)

4)      Compléter ces fonctions dans BoardGame.c.

5)      Dans FindtheExit.c, créer un Board contenant un petit labyrinthe. Compléter le jeu de façon à permettre à chaque joueur de trouver la sortie. Le premier des deux à y être a gagné. 

6)      Dans Othello.c, compléter les appels au board pour faire fonctionner le jeu. (http://fr.wikipedia.org/wiki/Othello_(jeu)) 
 
7)      Ajouter également un autre fichier .c décrivant le jeu de votre choix, qui utilisera lui aussi la bibliothèque de code partagée.

8)      Dans un fichier main.c créer une petite interface permettant de lancer l'application de son choix.
 
Les instructions demandées sont minimalistes. Vous pouvez ajouter des paramètres aux fonctions demandées et ajouter autant de fonctions que vous l'estimerez utile.
 
Envoyez-moi au plus tard le 19 mars au soir une archive zip ou rar (je n'accepterai aucun autre format) contenant les répertoires de travail habituels avec chaque fichier localisé au bon endroit. Un Makefile permettra de compiler et exécuter le programme. Ne vous inquiétez pas des chemins absolus vers votre installation de gcc ou autre par exemple, je les adapterai un minimum. 
 
J'accorderai plus d'attention au découpage en fonctions et fichiers propre qu'au bon fonctionnement de chaque jeu ou à leur rendu graphique. Tout peut être fait directement sur la console.
 
N'hésitez pas à m'envoyer un mail si vous êtes bloqués sur un point. 
 
Cordialement,
Nicolas Bellino

