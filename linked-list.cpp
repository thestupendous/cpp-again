// 

#include<iostream>
#include<vector>

struct nodeL {
	int data;
	nodeL * next;
};

void addFirst(nodeL * &head, int val);
void addLast(nodeL * &head, int val);
int popFirst(nodeL * &head);
int popLast(nodeL * &head);
void find(nodeL * &head, int val);
void popIfFound(nodeL * &head, int val);

void printL(nodeL * head);

int main() {
	nodeL * head = nullptr;

	for(int i=0;i<6;i++){
		addLast(head,i+1);
	}

	//printL(head);

	addFirst(head,99);
	//printL(head);

	addFirst(head,98);
	//printL(head);

	printL(head);
	popLast(head);
	printL(head);

	popFirst(head);
	printL(head);
	return 0;
}

void addLast(nodeL * &head, int val) {
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

void addFirst(nodeL * &head, int val) {
	nodeL * n = new nodeL {val,nullptr};
	if (head==nullptr) {
		head = n;
		return;
	} else {
		n->next = head;
		head = n;
	}
}


int popFirst(nodeL * &head) {
	if (head == nullptr) return -9999;
	int toReturn = head->data;
	head = head->next;
	return toReturn;
}

int popLast(nodeL * &head) {
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


void printL(nodeL * head) {
	nodeL * copy = head;
	while (copy!=nullptr) {
		std::cout << copy->data << ',';
		copy = copy->next;
	}
	std::cout << '\n';
}
