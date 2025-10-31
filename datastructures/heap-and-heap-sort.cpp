/*
 * MaxHeap 
 * vector to hold heap, last index var to hold last element + 1 index
*/

#include<iostream>
#include<vector>
using std::cout, std::vector;

void swap(int &a,int &b) {
	int t = a;
	a = b;
	b = t;
}

class Heap {
	vector<int> heapVec;
	unsigned int last;

public:

	Heap(): last{0}, heapVec{1}  {}
	Heap(vector<int> &vec) {
		if (heapVec.size() == 0) {
			heapVec.push_back(0);
			last = 0;
			return;
		}
		//heapVec.insert(heapVec.end(),vec.begin(),vec.end());
		cout << "  before\n";
		print();
		for ( int value : vec ) {
			cout << "pushing " << value << '\n';
			push(value);
		}
	}

	bool isEmpty(){
		if (heapVec.size() <= 1) {
			return true;
		}
		return false;
	}

	void push(int value){
		cout <<"inserting: " << value << '\n';

		if (last==0) {
			cout << "empty heap, pushing and exiting.\n";
			heapVec.push_back(value);
			++last;
			cout << "Log " << "1 done" << "\n";
		} else {
			++last;
			heapVec.push_back(value);
		  // print();
			// compare parents
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
	  // check empty heap
		if (heapVec.size() <= 1) {
			cout << "empty heap, can't pop!!\n";
			return -99999;
		} else if (heapVec.size() == 2) {
			int toReturn = heapVec[1];
			heapVec.pop_back();
			last=1;
			return toReturn;
		}

		// take out the top element (first in vector)
		// place last element on top, deleting last element position
		int toReturn = heapVec[1];
		heapVec[1] = heapVec[last--];
		heapVec.pop_back();

		// go down, swapping if necessary
		unsigned curr{1};
		unsigned maxInd{curr},left{curr*2}, right{curr*2+1};
		cout << ">>starting w " << heapVec[curr] << "\n";
		while(left <= last) {
			maxInd = curr;
			if (heapVec[maxInd] < heapVec[left]){
				cout << ">>maxed at left " << heapVec[left] << "\n";
				maxInd = left;
			}  
			if (right <= last && heapVec[maxInd] < heapVec[right]) {
				cout << ">>maxed at right " << heapVec[right] << "\n";
				maxInd = right;
			}

			if (maxInd == curr) {
				cout << ">>no further swapping ,\n";
				break;
			} else {
				cout << ">> Final swapping " << heapVec[curr] << " with "
					<< heapVec[maxInd] << '\n';
				swap(heapVec[curr],heapVec[maxInd]);
				curr = maxInd;
				left = curr*2;
				right = curr*2+1;
			}
		}
		return toReturn;
	}

	void print(){
		cout << ">heap size " << heapVec.size()-1 << '\n';
		cout << ">heap vector : [";
		for (int i: heapVec) {
			cout << i << ',';
		}
		cout << "]\n";
	}

};

int main() {
	vector<int> v1{5,2,6,10,1,11};
	Heap h1(v1);
	h1.print();
	cout << "pushing 200\n";
	h1.push(200);
	h1.print();
	h1.push(300);
	h1.print();
	h1.push(400);
	h1.print();
	h1.push(100);
	h1.print();
	h1.push(250);
	h1.print();
	h1.push(6);
	h1.print();

	cout<<">popping\n";
	int popped = h1.pop();
	cout << ">popped " << popped << '\n';
	h1.print();

	h1.push(90);
	h1.print();

	cout<<">popping\n";
	popped = h1.pop();
	cout << ">popped " << popped << '\n';
	h1.print();


	cout<<"\n";
  for (auto i{0};i<30;i++) {
		cout << "*-";
	} cout << "\n";

	cout << "Time for some HEAP SORT!!\n";
  for (auto i{0};i<30;i++) {
		cout << "*-";
	} cout << "\n";
	cout<<"\n";

	int arr2[] {3,-34,0,10,21,90,100,32,-234,59};
	Heap heap2;
	for (auto i: arr2) {
		heap2.push(i);
	}
	heap2.print();
	vector<int> sorted;
	while( !heap2.isEmpty() ){
		cout<<"popping\n";
		sorted.push_back( heap2.pop() );
	}

	cout << "[";
	for (auto i: sorted) {
		cout << i << ",";
	} cout << "]\n";

	return 0;
}
