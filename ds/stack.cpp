// stack using vector

#include<iostream>
#include<vector>
using std::cout,std::vector;

class Stack {
	vector<int> stackVec;
	int top;

public:
	Stack (): top(-1) {}

	void push(int val) {
		stackVec.push_back(val);
		top++;
	}
	int pop() {
		cout << "Popping: top: " << top << '\n';
		if ( (*this).empty() ) { 
			cout << "Stack already Empty! Can't pop from it\n";
			return -9999;
		}
		int toPop=stackVec[top];
		stackVec.pop_back();
		top--;
		return toPop;
	}
	int stop() {
		return stackVec[top];
	}
	bool empty() {
		if (top==-1 && stackVec.size() == 0) return true;
		else return false;
	}
	void print() {
		for (int i=0;i<=top;i++) {
			cout << stackVec[i] << ',';
		}
		cout << '\n';
	}
};


int main() {
	Stack st1;

	st1.push(1);
	st1.push(2);
	st1.push(11);
	st1.push(4);

	st1.print();
	st1.pop();
	st1.print();
	st1.pop();
	st1.pop();
	st1.print();
	st1.pop();
	st1.print();
	st1.pop();

	cout << st1.empty() << '\n';

	return 0;
}


