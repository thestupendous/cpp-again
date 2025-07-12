// single linked list without maintaining tail ptr
// TODO: to finish : after :
//   update calls to methods in main() function

#include<iostream>
#include<vector>

struct nodeL {
	int data;
	nodeL * next;
};

class LinkedList {
	nodeL * head;

public:
	LinkedList(): head(nullptr) {}

	void addFirst( int val);
	void addLast( int val);
	int popFirst();
	int popLast();
	int find(int toFind);
	bool findAndDelete(int toDelete);
	bool findAndUpdate(int toUpdate);
  void printL();
};


int main() {
	//nodeL * head = nullptr;
	LinkedList list1;

	for(int i=0;i<6;i++){
		list1.addLast(i+1);
	}
	//list1.printL(head);

#if 0 // testing all operations
	list1.addFirst(head,99);
	//list1.printL(head);

	list1.addFirst(head,98);
	//list1.printL(head);

	list1.printL(head);
	list1.popLast(head);
	list1.printL(head);

	list1.popFirst(head);
	list1.printL(head);
#endif

#if 0 // Testing popping 
	//list1.printL(nullptr);
	while (head!=nullptr) {
		list1.printL(head);
		list1.popLast(head);
	}
	list1.printL(head);
#endif 

#if 1 // Testing find and its variants
	list1.printL(head);
	std::cout << ( (list1.find(head,0) != -1) ? "found 0\n" : "0 not found\n" ) ;
	std::cout << ( (list1.find(head,3) != -1) ? "found 3\n" : "3 not found\n" ) ;
	std::cout << ( (list1.find(head,99) != -1) ? "found 99\n" : "99 not found\n" ) ;
	std::cout << ( (list1.find(head,1) != -1) ? "found 1\n" : "1 not found\n" ) ;
	std::cout << ( (list1.find(head,6) != -1) ? "found 6\n" : "6 not found\n" ) ;
	list1.printL(head);
	list1.findAndDelete(head,99);
	list1.printL(head);
	list1.findAndDelete(head,4);
	list1.printL(head);

	std::cout << "new list now\n";
	//nodeL * head2 = new nodeL {5,nullptr};
	LinkedList list2;
	list2.push(5);
	printL(head2);
	findAndDelete(head2,5);
	printL(head2);
#endif
	return 0;
}

void LinkedList::addLast( int val) {
	//std::cout <<"Test: got: "<<val<<'\n';
	nodeL * n = new nodeL {val,nullptr};
	if (head==nullptr) {
		head = n;
		return;
	} else {
		nodeL * headC = head;
		while (headC->next != nullptr) {
			headC = headC->next;
		}
		//std::cout <<"\tafter: "<<headC->data<<" Inserting: "<<n->data<<'\n';
		
		headC->next = n;
		return;
	}
}

void LinkedList::addFirst( int val) {
	nodeL * n = new nodeL {val,nullptr};
	if (head==nullptr) {
		head = n;
		return;
	} else {
		n->next = head;
		head = n;
	}
}


int LinkedList::popFirst() {
	if (head == nullptr) return -9999;
	int toReturn = head->data;
	head = head->next;
	return toReturn;
}

int LinkedList::popLast() {
	int toReturn=9999;
	if (head == nullptr) return toReturn; // list empty
	if (head->next == nullptr) { // only 1 element in lst
		toReturn = head->data;
		head = nullptr;
		return toReturn;
	}

	nodeL * headC = head;
	while (headC->next->next != nullptr) {
		headC = headC->next;
	}
	toReturn = headC->next->data;
	headC->next = nullptr;
	return toReturn;
}


void LinkedList::printL() {
	if (head == nullptr ) {
		std::cout << "Empty List!\n";
		return;
	}
	nodeL * copy = head;
	while (copy!=nullptr) {
		std::cout << copy->data << ',';
		copy = copy->next;
	}
	std::cout << '\n';
}

int LinkedList::find( int toFind) {
	if (head==nullptr) return false;
	int index {0};
	while(head!=nullptr) {
		if (head->data == toFind ) {
			return index;
		}
		head = head->next;
		index++;
	}
	return -1;
}

bool LinkedList::findAndDelete( int toDelete) {
	using std::cout;
	std::cout << "In findAndDelete\n";
	if (head==nullptr) { std::cout << "got empty list\n"; return false; }
	if (head->next == nullptr) {
		std::cout << "got single element list\n";
		if (head->data == toDelete) {
			cout<< "clearing whole list\n";
			head = nullptr;
			return true;
		}
		return false;
	}
	while(head->next != nullptr) {
		if (head->next->data == toDelete ) {
			head->next = head->next->next;
			std::cout << "found and deleted " << toDelete << " !\n";
			return true;
		}
		head = head->next;
	}
	std::cout << "couldnt find and delete " << toDelete << " !\n";
	return false;
}
