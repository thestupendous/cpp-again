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
//TODO: remove koiNahi
//      remove ZeroKatta class
//		checkWon() theek karna -chhota

enum options { khali, zero, katta, };
enum players {pehla,dusra,koiNahi};


class ZeroKatta 
{
	public:
		options zeroKatta;
};



class Won{
	public:
		players vijeta;
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

};

class Box
{
	 ZeroKatta khane[3][3]; // 3x3 matrix of zero-katta
	 bool checkPossible(int x,int y,players khiladi) //check if placing move is correct
	 {
		 //checck board ke bheetar ya nahi 
		 if(x<0 || x>2 || y<0 || y>2)
			 return false;

		 //check khali jagah
		 if( khane[x][y].zeroKatta==khali ) 
			 return true;

		 return false;
	 }

     //return if someone won, and who won
	//TODO :ye error codes ke sath yes/no dega
	//matlab ek struct/class dega
    void checkWon(players player,Won &won)
	 {
		 //upar se niche
		 if (( khane[0][0].zeroKatta == khane[1][0].zeroKatta &&
				 khane[1][0].zeroKatta == khane[2][0].zeroKatta )
			 || ( khane[0][1].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta == khane[2][1].zeroKatta )
			 || ( khane[0][2].zeroKatta == khane[1][2].zeroKatta &&
				 khane[1][2].zeroKatta == khane[2][2].zeroKatta )

			//baye se daye
			 || ( khane[1][0].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta == khane[1][2].zeroKatta )
			 || ( khane[0][0].zeroKatta == khane[0][1].zeroKatta &&
				 khane[0][1].zeroKatta == khane[0][2].zeroKatta )
			 || ( khane[2][0].zeroKatta == khane[2][1].zeroKatta &&
				 khane[2][1].zeroKatta == khane[2][2].zeroKatta )

			// tirchhe
			 || ( khane[0][0].zeroKatta == khane[1][1].zeroKatta &&
				 khane[1][1].zeroKatta == khane[2][2].zeroKatta )
			 || ( khane[2][0].zeroKatta == khane[2][1].zeroKatta &&
				 khane[2][1].zeroKatta == khane[2][2].zeroKatta )
			 )

            {
				won.jeeta=true;
				won.vijeta=player;
     		}
	 }

	public:
	 bool isBoardFull(){
		if ( khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		khane[0][0] != khali &&
		) return true;
		return false;
	 }



	 void placeMove(players player,int x,int y,Won& won)
	 {
		 if(!checkPossible(x,y,player)) {
			 //TODO: dubara input lo
			 return;
		 }
		
		 khane[x][y].kiska = player;
		 khane[x][y].zeroKatta = (static_cast<int>(player)==0)?zero:katta;

		 if(checkWon(player,won)){
			 won.vijeta = player;
			 jeeta = true;
		 }
	 }
};


	
	 

int main()
{
	//int score[2] = {0,0};  +bad
	int turn;
	//bool userFlip=false;  +bad


		Coords coords;
		Won won;
		Box khel();
		turn = 0; // +bad

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



}




