#include <iostream>
using std::cout;

class Aggregate{
	public:
		int x;
		int y;
		void print(){
			cout << x << ',' << y <<'\n';
		}
};

class NonAggregate{
		int x;
		int y;
	public:
		NonAggregate(){}
		NonAggregate(int x1,int y1):x(x1),y(y1){}
		void print(){
			cout << x << ',' << y <<'\n';
		}
};

int main(){
	Aggregate pair1 = {1,2};
	NonAggregate pair2(3,4);

	pair1.print();
	pair2.print();

	return 0;
}
