// queue implementation
// using std::list for linked list
#include<iostream>
#include<list>
using namespace std;

class Queue {
  list<int> qList;

public:
  Queue () {}

  void push(int val) {
		qList.push_back(val);
	}

  void pop() {
		if ( ! qList.empty() ) {
			qList.pop_front();
		} else {
			cout << "Error: can't pop from empty queue!\n";
		}
	}

  int front() {
		if (!qList.empty()) {
			return qList.front();
		} else { 
			cout << "Error: cant print front from empty list!\n";
			return -99999;
		}
	}

  bool empty() {
		return qList.empty();
	}
};

int main() {
	Queue q1;
	q1.push(1);
	q1.push(2);

	q1.push(3);
	cout << q1.front() << '\n';

	q1.pop();
	cout << q1.front() << '\n';
	
	if (q1.empty()) cout << "Empty!\n";
	else cout << "Not Empty!\n";

	q1.pop();
	cout << q1.front() << '\n';
	
	q1.pop();
	cout << q1.front() << '\n';
	
  return 0;
}
