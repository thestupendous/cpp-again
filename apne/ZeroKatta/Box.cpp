#include "headers.h"
#include "Box.h"

Box::Box()
{
	for (int i(0); i < 3; i++)
	{
		for (int j(0); j < 3; j++)
		{
			khane[i][j].zeroKatta = khali;
		}
	}
}

			// 3x3 matrix of zero-katta
bool Box::checkPossible(const Coords &coords) // check if placing move is correct
{
	int x = coords.x;
	int y = coords.y;
	// checck board ke bheetar ya nahi
	if (x < 0 || x > 2 || y < 0 || y > 2)
		return false;

	// check khali jagah
	if (khane[x][y].zeroKatta == khali)
		return true;

	return false;
}

// return if someone won, and who won
// TODO :ye error codes ke sath yes/no dega
// matlab ek struct/class dega
void Box::checkAndUpdateWon(players player, Won &won)
{
	// upar se niche
	if ((khane[0][0].zeroKatta == khane[1][0].zeroKatta &&
			khane[1][0].zeroKatta == khane[2][0].zeroKatta && khane[2][0].zeroKatta != khali) ||
		(khane[0][1].zeroKatta == khane[1][1].zeroKatta &&
			khane[1][1].zeroKatta == khane[2][1].zeroKatta && khane[2][1].zeroKatta != khali) ||
		(khane[0][2].zeroKatta == khane[1][2].zeroKatta &&
			khane[1][2].zeroKatta == khane[2][2].zeroKatta && khane[2][2].zeroKatta != khali)

		// baye se daye
		|| (khane[1][0].zeroKatta == khane[1][1].zeroKatta &&
			khane[1][1].zeroKatta == khane[1][2].zeroKatta && khane[1][2].zeroKatta != khali) ||
		(khane[0][0].zeroKatta == khane[0][1].zeroKatta &&
			khane[0][1].zeroKatta == khane[0][2].zeroKatta && khane[0][2].zeroKatta != khali) ||
		(khane[2][0].zeroKatta == khane[2][1].zeroKatta &&
			khane[2][1].zeroKatta == khane[2][2].zeroKatta && khane[2][2].zeroKatta != khali)

		// tirchhe
		|| (khane[0][0].zeroKatta == khane[1][1].zeroKatta &&
			khane[1][1].zeroKatta == khane[2][2].zeroKatta && khane[2][2].zeroKatta != khali) ||
		(khane[0][2].zeroKatta == khane[1][1].zeroKatta &&
			khane[1][1].zeroKatta == khane[2][0].zeroKatta && khane[2][0].zeroKatta != khali))

	{
		won.jeeta = true;
		won.vijeta = player;
	}
}


bool Box::isBoardFull()
{
	if (
		khane[0][0].zeroKatta != khali &&
		khane[0][1].zeroKatta != khali &&
		khane[0][2].zeroKatta != khali &&
		khane[1][0].zeroKatta != khali &&
		khane[1][1].zeroKatta != khali &&
		khane[1][2].zeroKatta != khali &&
		khane[2][0].zeroKatta != khali &&
		khane[2][1].zeroKatta != khali &&
		khane[2][2].zeroKatta != khali)
		return true;
	return false;
}

void Box::printBoard()
{
	cout << "\n";
	for (int i(0); i < 3; i++)
	{
		cout << " ";
		for (int j(0); j < 3; j++)
		{
			switch (khane[i][j].zeroKatta)
			{
			case zero:
				cout << 'O';
				break;
			case katta:
				cout << 'X';
				break;
			case khali:
				cout << '.';
				break;
			default:;
			}
			if (j < 2)
				cout << " | ";
		}
		if (i < 2)
			cout << "\n-----------\n";
	}
	cout << "\n\n";
}

void Box::placeMove(const int &turn, Coords &coords, Won &won)
{
	while (!checkPossible(coords))
	{
		cout<<"Jagah ghiri hui hai, firse prayas karein!! : \n";
        coords.setNewCoords(turn);
	}

	// khane[x][y].kiska = player;
	khane[coords.x][coords.y].zeroKatta = (turn == 0) ? zero : katta;

	players player((turn == 0) ? pehla : dusra);
	checkAndUpdateWon(player, won);
}
