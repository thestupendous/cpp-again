/* operations provided
 *  - add new node
 *  - traverse inorder
 *  - delete a node
 *  - print children of a node 
*/

#include<iostream>
#include<string>
#include<vector>
using std::cout,std::string,std::to_string,std::vector;
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
			delete parent->left;
			parent->left = nullptr;
			return;
		} else if (goRight) {
			delete parent->right;
			parent->right = nullptr;
			return;
		} else {
			cout << "Impossible\n";
			return;
		}
	}


	// right subtree doesn't exist
	if (ptr->right == nullptr) {
		Tree* temp = ptr;
		ptr = ptr->left;
		delete temp;
		return;
	} else { // right subtree does exist
	// find correct candidate in right subtree
		Tree *minimum {ptr->right}, *minimumParent;
		while (minimum -> left != nullptr) {
			minimumParent = minimum;
			minimum = minimum->left;
		}
		Tree* candidate{minimum};
		// minimum -> left = ptr->left;
		ptr->data = minimum->data;

		// actual deletion
		cout << "deleted, replaced by " << minimum->data << '\n';
		Tree* toDelete = minimum->left;
		if (minimum->right != nullptr) {
			minimumParent->left = minimum->right;
			delete toDelete;
		} else {
			minimumParent->left = nullptr;
			delete toDelete;
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
	vector<int> insertOrder;
	insertOrder.push_back(10);
	addNode(head,10);
	insertOrder.push_back(5);
	addNode(head,5);
	insertOrder.push_back(1);
	addNode(head,1);
	insertOrder.push_back(7);
	addNode(head,7);
	insertOrder.push_back(100);
	addNode(head,100);
	insertOrder.push_back(61);
	addNode(head,61);
	insertOrder.push_back(110);
	addNode(head,110);
	insertOrder.push_back(23);
	addNode(head,23);
	insertOrder.push_back(70);
	addNode(head,70);
	insertOrder.push_back(16);
	addNode(head,16);
	insertOrder.push_back(55);
	addNode(head,55);
	insertOrder.push_back(66);
	addNode(head,66);
	insertOrder.push_back(87);
	addNode(head,87);
	insertOrder.push_back(43);
	addNode(head,43);
	insertOrder.push_back(60);
	addNode(head,60);


	cout<<">> Insert order: [";
	for(auto i: insertOrder) {
		cout << i << ',';
	} cout << "]\n";

	traverse(head);
	cout<<'\n';

	cout<<">>deleting 10\n";
	deleteNode(head,10);
	traverse(head);
	cout<< '\n';

	children(*head,16);
	children(*head,23);

	return 0;
}
