#include<iostream>
#include<vector>
using std::cout, std::vector;

void swap(int &a,int &b) {
	int t = a;
	a= b;
	b= t;
}

class Heap {
	vector<int> heapVec;
	unsigned int last;

public:

	Heap(): last(0), heapVec(1)  {}
	Heap(vector<int> &vec) {
		if (heapVec.size() == 0) {
			heapVec.push_back(0);
			last = 0;
		}
		//heapVec.insert(heapVec.end(),vec.begin(),vec.end());
		cout << "  before\n";
		print();
		for ( int value : vec ) {
			cout << "pushing " << value << '\n';
			push(value);
		}
	}

	void push(int value){
		cout <<"inserting: " << value << '\n';

		if (last==0) {
			cout << "empty heap, pushing and exiting.\n";
			last = 1;
			heapVec[++last] = value;
			return;
		} else {
			++last;
			heapVec.push_back(value);
		  print();
			//compare parents
			int i = last;
			while (i/2 >= 1 ) {
				if (heapVec[i] > heapVec[i/2]) {
					swap(heapVec[i],heapVec[i/2]);
					cout << "  swapping " << heapVec[i] << " and " << heapVec[i/2] << '\n';
				}
				i /= 2;

			}
		}
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
	cout << "pushing 200\n";
	h1.push(200);
	h1.print();

	return 0;
}
