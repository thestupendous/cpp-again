#include<iostream>
#include<vector>
using std::cout, std::vector;

class Heap {
	vector<int> heapVec;

public:

	Heap()  {}
	Heap(vector<int> &vec): heapVec(vec.size()+1) {}

	void push(){

	}

	int pop(){
		return 0;
	}

	void print(){
		cout << "heap size " << heapVec.size() << '\n';
		for (int i: heapVec) {
			cout << i << ',';
		}
		cout << '\n';
	}

};

int main() {
	vector<int> v1{5,2,6,10,1,11};
	Heap h1(v1);
	h1.print();

	return 0;
}
