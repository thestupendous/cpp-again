#include<iostream>
#include "headers.h"
using std::cout;
using std::cin;

int main()
{
	Score score; 
	int userFlip=0;  

	int turn = 0;
	


	while (1)
	{
		turn=userFlip;
		Coords coords;
		Won won;
		Box khel; // +bad
		cout << "\n\nNEW GAME\n" ;

		while (1) // khel khilane ke liye
		{

			khel.printBoard();

			// process for turn wala player
			coords.setNewCoords(turn);
			// TODO: func playerCoords(turn,coords)
			// jiska turn ho wahi input de !

			khel.placeMove(turn, coords, won);
			// matlab 1.checksahi moove, 2.placeMove
			// move ke bad bhi jeeta ya nai, yahi func
			// evaluate karega, -> 3.checkWon

			if (won.jeeta)
			{
				break;
			}
			if (khel.isBoardFull())
			{
				break;
			}

			turn = (turn == 0) ? 1 : 0;
		}

		khel.printBoard();

		if (won.jeeta)
		{
			printYeWalaGameEndingText(won.vijeta);
			score.update(won.vijeta);
			
		}
		else
		{
			printDrawGameText();
		}
		score.print();

		if(! wantToContinue())
		{
			break;
		}

		flipTurn(userFlip);
	}

	cout << "-----------------------------Thanks for playing-----------------------------\n";

	return 0;
}