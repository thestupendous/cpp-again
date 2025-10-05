#include<iostream>
using std::cout;
// tree = bst

struct Tree {
	int data;
	Tree *left;
	Tree *right;
	Tree (int val) : data(val), left(nullptr), right(nullptr) {
	}
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

void addNode(Tree* &head,const int& val) {
	// cout << "log: " << "Called\n";
	Tree * node = new Tree(val);
	if (head == nullptr) {
		cout << "log: " << "adding first\n";
		head = node;
		return;
	}
	//traverse
	Tree* ptr = head;
	while ( ptr != nullptr ) {
		if (ptr->data > val) {
			//go left
			if (ptr->left != nullptr) {
				ptr = ptr->left;
			} else {
				ptr->left = node;
				return;
			}
		} else {
			// go right
			if (ptr->right != nullptr ) {
				ptr = ptr->right;
			} else {
				ptr->right = node;
				return;
			}
		}
	}
}

void deleteNode(Tree* &head, int val) {
	// find val
	Tree* ptr = head;
	while (ptr != nullptr) {
		if (ptr->data == val)
			break;
		else if (val < ptr->data) {
			ptr = ptr->left;
		}
		else if (val > ptr->data) {
			ptr = ptr->right;
		}
	}
	if (ptr == nullptr) {
		cout << "node not found, can't delete!!\n";
		return;
	}

	// right subtree exists?
	if (ptr->right == nullptr) {
		ptr = ptr->left;
	} else {
	// find correct candidate in right subtree
		Tree* minimum = ptr;
		while (minimum -> left != nullptr) {
			minimum = minimum->left;
		}
		Tree* candidate = minimum;
		minimum -> left = ptr->left;
		ptr = minimum;
		cout << "deleted, replaced by " << minimum->data;
	}


}

int main() {
	Tree *head = nullptr;
	addNode(head,10);
	addNode(head,5);
	addNode(head,15);
	addNode(head,7);
	addNode(head,20);

	traverse(head);
	cout<<'\n';

	deleteNode(head,10);
	traverse(head);
	cout<< '\n';

	return 0;
}
