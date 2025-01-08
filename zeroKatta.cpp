#include<iostream>
/*
 * classes
 *
 * Box - khel
 * Won
 * Coords 
 * Score 
*/

Enum options { khali, zero, katta, };
Enum players {pehla,dusra,koiNahi};

class Won{
	public:
		player vijeta;
		bool jeeta;
		//Won():vijeta(koiNahi),jeeta(false){};
};

int getInputInt()
{
	int num;
	std::cin>>num;
	return num;
}

//functions 
printYeWalaGameEndingText(won)

class Coords{
	public:
		int x,y;
		Coords(int a,int b):x(a),b(b) {}
		void setNewCoords(){
			x = getInputInt();
			y = getInputInt();
		}

}

class Box
{
	 options Khane[3][3]; // 3x3 matrix of zero-katta
	 bool checkPossible(int x,int y); //check if placing move is correct
	 Won checkWon(); //return if someone won, and who won
					 //TODO :ye error codes ke sath yes/no dega
					 //matlab ek struct/class dega
	public:
	 placeMove(players,int x,int y,Won& won)
	 {
		 if(!checkPossible(x,y)) {
			 //TODO: dubara input lo
			 return;
		 }
		 
		 Khane[x][y]

			 
		 }
	 }
	 bool boardFull();
};

class Score
{
	public:  
	int score[2];
	Score(){
		score[pehla]=0;
		score[dusra]=0;
	}
	void updateScore(won){
		;
	}

}
	
	 

int main()
{
	int score[2] = {0,0};
	int turn;
	bool userFlip=false;

	while (1)  //kai sare khel
	{ 
		turn = (userFlip)?1:0;
		Coords coords;
		Won won;
		Box khel();
		while (1)  //khel khilane ke liye
		{

			//process for turn wala player
			coords.setNewCoords();
			//TODO: func playerCoords(turn,coords) 
					//jiska turn ho wahi input de !

			khel.placeMove(turn,coords,won);
				// matlab checksahi 1.moove, 2.placeMove
				// move ke bad bhi jeeta ya nai, yahi func 
				// evaluate karega, -> 3.checkWon 

			if(won.jeeta) {
				break;
			}
			if (khel.boardFull()){
				break;
			}

			turn = (turn==0) ? 1  : 0 ;
		}


		// iske bajaye sab ek function me
		printYeWalaGameEndingText(won)
		updateScore(won); // yaha par

		if(!wannaContinue()){
			printByeBye();
			break;
		}



		userFlip = !userFlip;
	}


}




