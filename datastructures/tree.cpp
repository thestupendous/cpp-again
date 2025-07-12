/* bst 
 * operations -
 *   . insert new
 *   . traverse
 *   . delete
*/
#include<iostream>

struct tnode {
	int data;
	tnode *left;
	tnode *right;
};

class Tree {
	tnode * head;

public:

	Tree():	head(nullptr) {}
	void insert(int);
	void traverse();
	void deleteNode(int);
};

int main() {
}

void Tree::insert(int value) {
	tnode *newNode = new tnode{value,nullptr,nullptr};
	if (head==nullptr) {
		head = newNode;
		return;
	} else {
		tnode *p = head;
		while ( p!=nullptr ) {
			if ( (*p)->data < value ) {
				//go left
				p = p->left;
			} else 
	}

}
