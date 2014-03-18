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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] ='0';
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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
                      break;
                  }
                  break;
                case 5:
                  switch (l)
                  {
                    case 1:
                    case 2:
                    case 5:
                    case 6:
                    case 7:
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
                      break;
                  }
                  break;
                case 6:
                  switch (l)
                  {
                    case 3:
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
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
                      labi.tabBoard[c][l] = '1';
                      break;
                    default:
                      labi.tabBoard[c][l] = '0';
                      break;
                  }
                  break;
              }
        }
    }
    afficherBoard(labi);
  labi.tabBoard[0][0] = '2';
  c = 0;
  l = 0;
  int tour = 1;
  while (labi.tabBoard[7][7] != '2')
    {
      printf("Tour %d\n", tour);
      printf("Vous pouvez allez : \n");
      if (c>0)
      {
        if (labi.tabBoard[c-1][l] == '1')
        {
          printf("A gauche (entrer G)\n");
        }
      }
      if (c<7)
      {
        if (labi.tabBoard[c+1][l] == '1')
        {
          printf("A droite (entrer D)\n");
        }
      }
      if (l>0)
      {
        if (labi.tabBoard[c][l-1] == '1')
        {
          printf("En haut (entrer H)\n");
        }
      }
      if (l<7)
      {
        if (labi.tabBoard[c][l+1] == '1')
        {
          printf("En bas (entrer B)\n");
        }
      }
      char direc = ' ';
      printf("qqch");
      while(direc != 'G' && direc != 'D' && direc != 'H' && direc != 'B')
      {
        scanf("%c", direc);
        switch (direc)
        {
            case 'G' :
              Move(labi, c-1, l);
              break;
            case 'D' :
              Move(labi, c+1, l);
              break;
            case 'H' :
              Move(labi, l-1, l);
              break;
            case 'B' :
              Move(labi, l+1, l);
              break;
            default :
              printf("Mauvaise direction\n Rentrez une direction valide :");
              break;
        }
      }      
      tour ++;
    }
    printf("Bravo vous avez gagé en %d tours!", (tour - 1));
}
