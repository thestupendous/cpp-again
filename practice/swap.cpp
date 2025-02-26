#include<iostream>
using namespace std;

void swap(int &n1,int &n2){
	int t = n1;
	n1 = n2;
	n2 = t;
}

// swap two numbers by reference
int main() {
	int a{5},b{-3};
	cout << a << ',' << b << '\n' ;
	swap(a,b);
	cout << a << ',' << b << '\n' ;

	return 0;
}

