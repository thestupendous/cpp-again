#include "headers.h"


void Coords::setNewCoords(int turn)
{
	cout << "Enter coords for player" << turn+1 << ", [1-9] ek number : ";
	int temp; 
	cin>>temp; //1-9
	while(temp<0 || temp>9 )
		{
			cout << "dhang se enter kar (1 se 9 tak koi number ) : ";
			cin>>temp; //1-9
		}

	--temp;
	x = temp/3;
	y = temp%3;
	//readInputInt(x);
	//readInputInt(y);
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

