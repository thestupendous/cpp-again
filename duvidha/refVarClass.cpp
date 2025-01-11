#include<iostream>
using namespace std;

class Pata 
{
	int x;
	double y;
	public:
	Pata(){}
	double & get(){
		return y;
	}

	double check(){
		return y;
	}
	void set(int v){
		y=v;
	}
};

int main()
{
	Pata ob;
	ob.set(10);
	cout << ob.check() << '\n';
	ob.get() = 305;
	cout << ob.check() << '\n';

//	cout << ob.check() << '\n';
	return 0;
}
