#include "FindtheExit.h"

void partieFindTheExit()
{
  int l,c;
  Board labi;
  labi = InitializeBoard(labi);
  for (l=0; l<8; l++)
    {
        for (c=0; c<8; c++)
        {
              switch (c)
              {
                case 0:
                  switch (l)
                  {
                    case 0:
                    case 2:
                    case 3:
                    case 4:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 1:
                  switch (l)
                  {
                    case 0:
                    case 1:
                    case 2:
                    case 4:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 2:
                  switch (l)
                  {
                    case 5:
                    case 6:
                    case 7:
                    case 4:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 3:
                  switch (l)
                  {
                    case 1:
                    case 2:
                    case 3:
                    case 7:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 4:
                  switch (l)
                  {
                    case 1:
                    case 5:
                    case 3:
                    case 4:
                    case 7:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 5:
                  switch (l)
                  {
                    case 1:
                    case 2:
                    case 3:
                    case 5:
                    case 6:
                    case 7:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 6:
                  switch (l)
                  {
                    case 3:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
                case 7:
                  switch (l)
                  {
                    case 5:
                    case 6:
                    case 7:
                    case 2:
                    case 3:
                    case 4:
                      labi.tabBoard[c][l] = ' ';
                      break;
                    default:
                      labi.tabBoard[c][l] = (char)219;
                      break;
                  }
                  break;
              }
        }
    }
  labi.tabBoard[0][0] = 'X';
  afficherBoard(labi);
  c = 0;
  l = 0;
  int tour = 1;
  while (labi.tabBoard[7][7] != 'X')
    {
      printf("Tour %d\n", tour);
      printf("Vous pouvez allez : \n");
      if (c>0)
      {
        if (labi.tabBoard[c-1][l] == ' ')
        {
          printf("A gauche (entrer G)\n");
        }
      }
      if (c<7)
      {
        if (labi.tabBoard[c+1][l] == ' ')
        {
          printf("A droite (entrer D)\n");
        }
      }
      if (l>0)
      {
        if (labi.tabBoard[c][l-1] == ' ')
        {
          printf("En haut (entrer H)\n");
        }
      }
      if (l<7)
      {
        if (labi.tabBoard[c][l+1] == ' ')
        {
          printf("En bas (entrer B)\n");
        }
      }
      char direc = ' ';
      while(direc != 'G' && direc != 'D' && direc != 'H' && direc != 'B')
      {
        int debug = 0;
        printf("Rentrez une direction :\n");
        f_purge();
        debug = scanf("%c", &direc);
        switch (direc)
        {
            case 'G' :
              if (labi.tabBoard[c-1][l] == ' ')
              {
                labi.tabBoard[c][l] = ' ';
                c -= 1;
                labi.tabBoard[c][l] = 'X';
              }
              else
              {
                printf("Vous comptez traverser les murs?\n");
              }
              break;
            case 'D' :
              if (labi.tabBoard[c+1][l] == ' ')
              {
                labi.tabBoard[c][l] = ' ';
                c += 1;
                labi.tabBoard[c][l] = 'X';
              }
              else
              {
                printf("Vous comptez traverser les murs?\n");
              }
              break;
            case 'H' :
              if (labi.tabBoard[c][l-1] == ' ')
              {
                labi.tabBoard[c][l] = ' ';
                l -= 1;
                labi.tabBoard[c][l] = 'X';
              }
              else
              {
                printf("Vous comptez traverser les murs?\n");
              }
              break;
            case 'B' :
              if (labi.tabBoard[c][l+1] == ' ')
              {
                labi.tabBoard[c][l] = ' ';
                l += 1;
                labi.tabBoard[c][l] = 'X';
              }
              else
              {
                printf("Vous comptez traverser les murs?\n");
              }
              break;
            default :
              printf("Mauvaise direction\n Rentrez une direction valide :\n");
              break;
        }
      } 
      afficherBoard(labi);     
      tour ++;
    }
    printf("Bravo vous avez gagé en %d tours!", (tour - 1));
}
