// implemnting a normal tree datastructure (with any number of
//   children

#include <iostream>
#include <string>
#include <vector>
using std::cout,std::string,std::vector;

struct Tree {
	// node info
	string nodeID;
	int data;

	// children info;
	unsigned noOfChildren;
	vector<Tree*> children;
};

void traverse(const Tree* head) {
	if (head->left != nullptr) {
		traverse(head->left);
	}

	cout << head->data << ',';

	if (head->right != nullptr) {
		traverse(head->right);
	}
}


int main() {
	Tree *head;
}
