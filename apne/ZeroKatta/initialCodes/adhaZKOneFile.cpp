#include <iostream>
using namespace std;
/*
 * classes
 *
 * Box - khel
 * Won
 * Coords
 * Score
 * ZeroKatta X
 */
// TODO: remove koiNahi
//       remove ZeroKatta class
//		checkWon() theek karna -chhota
//		getline() for input

enum options
{
	khali,
	zero,
	katta,
};
enum players
{
	pehla,
	dusra,
	koiNahi
};

class ZeroKatta
{
public:
	options zeroKatta;
};

class Won
{
public:
	players vijeta;
	bool jeeta;
	Won() : jeeta(false) {};
};

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

class Coords
{
public:
	int x, y;
	Coords()
	{
		x = -1;
		y = -1;
	}
	Coords(int a, int b) : x(a), y(b) {}
	void setNewCoords()
	{
		cout << "Enter coords: ";
		readInputInt(x);
		readInputInt(y);
	}
};

class Box
{
	ZeroKatta khane[3][3];					 // 3x3 matrix of zero-katta
	bool checkPossible(const Coords &coords) // check if placing move is correct
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
	void checkAndUpdateWon(players player, Won &won)
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

public:
	Box()
	{
		for (int i(0); i < 3; i++)
		{
			for (int j(0); j < 3; j++)
			{
				khane[i][j].zeroKatta = khali;
			}
		}
	}

	bool isBoardFull()
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

	void printBoard()
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

	void placeMove(const int &turn, const Coords &coords, Won &won)
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
};

int main()
{
	// int score[2] = {0,0};  +bad
	// int turn;
	// bool userFlip=false;  +bad


	Coords coords;
	Won won;
	Box khel;
	int turn = 0; // +bad

	while (1) // khel khilane ke liye
	{

		khel.printBoard();

		// process for turn wala player
		coords.setNewCoords();
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
		;
	}
	khel.printBoard();

	if (won.jeeta)
	{
		printYeWalaGameEndingText(won.vijeta);
	}
	else
	{
		printDrawGameText();
	}
}
