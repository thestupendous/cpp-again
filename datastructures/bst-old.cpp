// insert and traverse only
#include<iostream>
using namespace std;

struct tnode {
	int data;
	tnode *left;
	tnode *right;
};

class bst {
	tnode *root;

	void traverse2(tnode *r2) {
		if (r2 == nullptr) return;

		traverse2(r2->left);

		std::cout << r2->data << ',';
		
		traverse2(r2->right);
	}

public:
	bst():root(nullptr) {}

	void insert(int value) {
		tnode *newNode = new tnode{value,nullptr,nullptr};
		if ( root == nullptr ) {
			root = newNode;
			return;
		}
		tnode *p = root;
		while ( p->left != nullptr || p->right != nullptr ) {

			if ( value < p->data ) {
				// go left
				if (p->left != nullptr) {
					p = p->left;
				} else {
					p->left = newNode;
					return;
				}
			} else {
				// go right
				if (p->right != nullptr) {
					p = p->right;
				} else {
					p->right = newNode;
					return;
				}
			}
		}
	  if ( value < p->data ) {
	  	p->left = newNode;
	  	return;
	  } else {
	  	p->right = newNode;
	  	return;
	  }
	}

	void insertWithLogging(int value) {
		std::cout << "inserting " << value << '\n' ;
		tnode *newNode = new tnode{value,nullptr,nullptr};
		if ( root == nullptr ) {
			root = newNode;
			return;
		}
		tnode *p = root;
		while ( p->left != nullptr || p->right != nullptr ) {
		  std::cout << "  inwhile, at " << value << '\n' ;

			if ( value < p->data ) {
		    std::cout << "  value less than " << p->data << " going left\n" ;
				// go left
				if (p->left != nullptr) {
					p = p->left;
				} else {
					p->left = newNode;
					std::cout << "  inserted left\n";
					return;
				}
			} else {
		    std::cout << "  value more than " << p->data << " going right\n" ;
				// go right
				if (p->right != nullptr) {
					p = p->right;
				} else {
					p->right = newNode;
					std::cout << "inserted right\n";
					return;
				}
			}
		}
	  if ( value < p->data ) {
	  	p->left = newNode;
	  	return;
	  } else {
	  	p->right = newNode;
	  	return;
	  }
	}

	void traverse() {
		std::cout << "whole tree : ";
		traverse2(root);
		std::cout << '\n';
	}
};

int main() {
	std::cout << '\n';
	int input [] = {5,3,10,6,12};
	bst t1;
	for ( int i : input ) {
		t1.insert(i);
	}

	t1.traverse();
	
	return 0;
}
