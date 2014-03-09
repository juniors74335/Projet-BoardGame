#include "BoardGame.h"

Board labi;
void partieFindTheExit()
{
	int l,c;
	Board labi;
	Initialize();
	InitializeBoard(labi);
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
}