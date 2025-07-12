// NOTE: the thing tested here wrt && and pointers works in c++ only
//     and it DOES NOT WORK IN PYTHON 
#include<iostream>
using namespace std;

int main() {
	int a = 10;
	int *p = nullptr;
	//p = &a;
	
	if (a<20) {
		cout << "less thn 20\n";
	}

	if (p!=nullptr && (*p)==10) {
		cout << "pointer 10\n";
	} else {
		cout << "not ptr, ptr = "<< (*p) << '\n';
	}

	return 0;
}
