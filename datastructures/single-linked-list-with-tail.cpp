// single linked list wit maintaining tail ptr
// found that tail for end node is not useful for deletion operation
//    thus i think i'll leave 
//    things that can make it running are:
//      keep a preTail ptr, pointing to node before tail
//      then deletetion can also be done
//TODO: I've made class for LL, so all functions need to be modified
//      to be members of class 
//      methods updated:
//         addFirst()
//         addLast()
//      note:findAndDelete() cant be updated without adding another
//        tail

#include<iostream>
#include<vector>

struct nodeL {
	int data;
	nodeL * next;
};

class TailedList {
	nodeL * head;
	nodeL * tail;

	TailedList () : head(nullptr), tail(nullptr) {}

  void addFirst( int val);
  void addLast( int val);
  int popFirst();
  int popLast();
  int find( int toFind);
  bool findAndDelete( int toDelete);
  bool findAndUpdate( int toUpdate);
}


void printL(nodeL * head);

int main() {
	nodeL * head = nullptr;

	for(int i=0;i<6;i++){
		addLast(head,i+1);
	}
	//printL(head);

#if 0 // testing all operations
	addFirst(head,99);
	//printL(head);

	addFirst(head,98);
	//printL(head);

	printL(head);
	popLast(head);
	printL(head);

	popFirst(head);
	printL(head);
#endif

#if 0 // Testing popping 
	//printL(nullptr);
	while (head!=nullptr) {
		printL(head);
		popLast(head);
	}
	printL(head);
#endif 

#if 1 // Testing find and its variants
	printL(head);
	std::cout << ( (find(head,0) != -1) ? "found 0\n" : "0 not found\n" ) ;
	std::cout << ( (find(head,3) != -1) ? "found 3\n" : "3 not found\n" ) ;
	std::cout << ( (find(head,99) != -1) ? "found 99\n" : "99 not found\n" ) ;
	std::cout << ( (find(head,1) != -1) ? "found 1\n" : "1 not found\n" ) ;
	std::cout << ( (find(head,6) != -1) ? "found 6\n" : "6 not found\n" ) ;
	printL(head);
	findAndDelete(head,99);
	printL(head);
	findAndDelete(head,4);
	printL(head);

	std::cout << "new list now\n";
	nodeL * head2 = new nodeL {5,nullptr};
	printL(head2);
	findAndDelete(head2,5);
	printL(head2);
#endif
	return 0;
}

void TailedList::addFirst( int val) {
	nodeL * n = new nodeL {val,nullptr};
	if (head==nullptr) {
		head = n;
		tail = n;
		return;
	} else {
		n->next = head;
		head = n;
	}
}

void TailedList::addLast( int val) {
	//std::cout <<"Test: got: "<<val<<'\n';
	nodeL * n = new nodeL {val,nullptr};
	if (head==nullptr) {
		head = n;
		tail = n;
		return;
	} else {
		tail->next = n;
		tail = tail->next;
	}
}

int TailedList::popFirst() {
	if (head == nullptr) return -9999;
	int toReturn = head->data;
	head = head->next;
	return toReturn;
}

int TailedList::popLast() {
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


void TailedList::printL() {
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

int TailedList::find( int toFind) {
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

bool TailedList::findAndDelete( int toDelete) {
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

bool TailedList::findAndUpdate( int toUpdate) {
	return false;
}
