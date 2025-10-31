/* operations provided
 *  - add new node
 *  - traverse inorder
 *  - delete a node
 *  - print children of a node 
*/

#include<iostream>
#include<string>
using std::cout,std::string,std::to_string;
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
#if 0
	if (head->data == val) {
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
#endif

	// find node to delete
	Tree *ptr = head,*parent = head;
	bool goLeft{false}, goRight{false};
	while (ptr != nullptr) {
		if (ptr->data == val)
			break;
		else if (val < ptr->data) {
			// go left
			parent = ptr;
			goLeft = true;
			ptr = ptr->left;
		}
		else {
			// go right
			parent = ptr;
			goRight = true;
			ptr = ptr->right;
		}
	}
	if (ptr == nullptr) {
		cout << "node not found, can't delete!!\n";
		return;
	} else if ( ptr->left == nullptr && ptr->right == nullptr ) {
		// it is a leaf node
		cout << "found a leaft node to delete\n";
		if (goLeft) {
			parent->left = nullptr;
			return;
		} else if (goRight) {
			parent->right = nullptr;
			return;
		} else {
			cout << "Impossible\n";
			return;
		}
	}


	// right subtree exists?
	if (ptr->right == nullptr) {
		ptr = ptr->left;
		return;
	} else {
	// find correct candidate in right subtree
		Tree *minimum = ptr->right, *minimumParent;
		while (minimum -> left != nullptr) {
			minimumParent = minimum;
			minimum = minimum->left;
		}
		Tree* candidate = minimum;
		// minimum -> left = ptr->left;
		ptr->data = minimum->data;

		// actual deletion
		cout << "deleted, replaced by " << minimum->data << '\n';
		if (minimum->right != nullptr) {
			minimumParent->left = minimum->right;
		} else {
			minimumParent->left = nullptr;
		}
	}

}

void children(const Tree &node,const int & val) {
	// find node
	const Tree* ptr = &node;
	while (ptr != nullptr) {
		if (ptr->data == val) {
			break;
		} else if (val < ptr->data) {  // go left
			ptr = ptr->left;
		} else { // go right
			ptr = ptr->right;
		}
	}
	if (ptr == nullptr) {
		cout << "value not found, can't print children\n";
		return;
	}

	// print children
	cout << "      " << ptr->data << '\n';
	cout << "    /     \\\n";
	cout << ( (ptr->left!=nullptr) ? to_string(ptr->left->data) : "X") << "         " <<
		( (ptr->right!=nullptr)? to_string(ptr->right->data) : "X" ) << '\n';
}

int main() {
	Tree *head = nullptr;
	addNode(head,10);
	addNode(head,5);
	addNode(head,1);
	addNode(head,7);
	addNode(head,100);
	addNode(head,61);
	addNode(head,110);
	addNode(head,23);
	addNode(head,70);
	addNode(head,16);
	addNode(head,55);
	addNode(head,66);
	addNode(head,87);
	addNode(head,43);
	addNode(head,60);

	traverse(head);
	cout<<'\n';

	deleteNode(head,10);
	traverse(head);
	cout<< '\n';

	children(*head,16);
	children(*head,23);

	return 0;
}
