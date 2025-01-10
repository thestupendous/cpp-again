#include "headers.h"




void Coords::setNewCoords(int turn)
{
	cout << "Enter coords for player " << turn+1 << ": ";
	int temp; cin>>temp; //1-9
	--temp;
	x = temp/3;
	y = temp%3;
	//readInputInt(x);
	//readInputInt(y);
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

void Box::placeMove(const int &turn, const Coords &coords, Won &won)
{
	if (!checkPossible(coords))
	{
		// TODO: dubara input lo
		return;
	}

	// khane[x][y].kiska = player;
	khane[coords.x][coords.y].zeroKatta = (turn == 0) ? zero : katta;

	players player((turn == 0) ? pehla : dusra);
	checkAndUpdateWon(player, won);
}


void readInputInt(int &num)
{
	std::cin >> num;
}

// functions
// printGameStartingText();  +bad

void printYeWalaGameStartingText()
{
	cout << "welcome, game starts\n turn starts with player1\n";
	cout << "Enter coords: ";
}

// printGameEndingText(won);  +bad

void printYeWalaGameEndingText(players vijeta)
{
	cout << "\n\nGAME OVER!\n\tPlayer" << (static_cast<int>(vijeta) + 1) << "\n\n";
}

void printDrawGameText()
{
	cout << "\n\nDRAW GAME!\n\tKOI NAI JEEETA (NO ONE WON!!)\n\n";
}

// wannaContinue();  +bad



void flipTurn(int &turn)
{
	turn = (turn == 0) ? 1 : 0;
}


Score::Score()
{
	score[0] = 0;
	score[1] = 0;
}
void Score::update(players vijeta)
{
	if (vijeta == pehla)
		score[0]++;
	else
		score[1]++;
}
void Score::print()
{
	cout << "Scores -\n";
	cout << "Player1 : " << score[0] << "\n";
	cout << "Player2 : " << score[1] << "\n";
	cout << "\n\n";
}


bool wantToContinue()
{
	cout << "do you want to continue playing? [y/n] : ";
		char con;
		cin >> con;
	if(con=='y' || con=='Y')
		return true;
	else if(con=='n' || con=='N')
		return false;
	else
		//technically error should be returned, but
		return true;
}

