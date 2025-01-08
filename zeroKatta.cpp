#include<iostream>
/*
 * classes
 *
 * Box - khel
 * Won
 * Coords 
 * Score 
 * ZeroKatta
*/

Enum options { khali, zero, katta, };
Enum players {pehla,dusra,koiNahi};


class ZeroKatta 
{
	public:
		options zeroKatta;
};



class Won{
	public:
		player vijeta;
		bool jeeta;
		Won():jeeta(false){};
};

constexpr int getInputInt()
{
	int num;
	std::cin>>num;
	return num;
}

//functions 
//printGameStartingText();  +bad
printYeWalaGameStartingText();
//printGameEndingText(won);  +bad
printYeWalaGameEndingText(won);
//wannaContinue();  +bad

class Coords
{
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
	 ZeroKatta khane[3][3]; // 3x3 matrix of zero-katta
	 bool checkPossible(int x,int y,player khiladi) //check if placing move is correct
	 {
		 //checck board ke bheetar ya nahi 
		 if(x<0 || x>2 || y<0 || y>2)
			 return false;

		 //check khali jagah
		 if(khane[x][y].kiska == koiNahi && khane[x][y].zeroKatta==khali ) 
			 return true;

		 return false;
	 }


	 Won checkWon() //return if someone won, and who won
					 //TODO :ye error codes ke sath yes/no dega
					 //matlab ek struct/class dega
	 {
		 //upar se niche
		 if (( khane[0][0].zeroKatta == khane[1][0].zeroKatta &&
				 khane[1][0].zeroKatta khane[2][0].zeroKatta )
			 || ( khane[0][1].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta khane[2][1].zeroKatta )
			 || ( khane[0][2].zeroKatta == khane[1][2].zeroKatta &&
				 khane[1][2].zeroKatta == khane[2][2].zeroKatta )

			//baye se daye
			 || ( khane[1][0].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta khane[1][2].zeroKatta )
			 || ( khane[0][0].zeroKatta == khane[0][1].zeroKatta &&
				 khane[0][1].zeroKatta khane[0][2].zeroKatta )
			 || ( khane[2][0].zeroKatta == khane[2][1].zeroKatta &&
				 khane[2][1].zeroKatta == khane[2][2].zeroKatta )

			// tirchhe
			 || ( khane[0][0].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta == khane[2][2].zeroKatta )
			 || ( khane[2][0].zeroKatta == khane[2][1].zeroKatta &&
				 khane[2][1].zeroKatta == khane[2][2].zeroKatta )
			 )








                                                       

  

	public:
	 bool isBoardFull();
	 placeMove(players player,int x,int y,Won& won)
	 {
		 if(!checkPossible(x,y,player)) {
			 //TODO: dubara input lo
			 return;
		 }
		
		 khane[x][y].kiska = player;
		 khane[x][y].zeroKatta = (static_cast<int>(player)==0)?zero:katta;

		 if(checkWon()){
			 won.vijeta = player;
			 jeeta = true;
		 }
	 }
};

#if 0 // +bad
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

};
#endif
	
	 

int main()
{
	//int score[2] = {0,0};  +bad
	int turn;
	//bool userFlip=false;  +bad

#if 0  //keval ek game

	printGameStartingText();
	// andrew player 1, jhandrew player2
	
	while (1)  //kai sare khel
	{ 
		turn = (userFlip)?1:0;
		Coords coords;
		Won won;
		Box khel();
		printYeWalaGameStartingText();
		// is bar player1 ya 2 pehle khelega
#endif
		Coords coords;
		Won won;
		Box khel();
		turn = 0 // +bad

		while (1)  //khel khilane ke liye
		{

			//process for turn wala player
			coords.setNewCoords();
			//TODO: func playerCoords(turn,coords) 
					//jiska turn ho wahi input de !

			khel.placeMove(turn,coords,won);
				// matlab 1.checksahi moove, 2.placeMove
				// move ke bad bhi jeeta ya nai, yahi func 
				// evaluate karega, -> 3.checkWon 

			if(won.jeeta) {
				break;
			}
			if (khel.isBoardFull()){
				break;
			}

			turn = (turn==0) ? 1  : 0 ;
		}

#if 0  //keval ek game
		// iske bajaye sab ek function me
		printYeWalaGameEndingText(won)
		updateScore(won); // yaha par

		if(!wannaContinue()){
			printByeBye();
			break;
		}



		userFlip = !userFlip;
	}
#endif

}




