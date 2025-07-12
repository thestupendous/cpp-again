#include<iostream>
using namespace std;

struct str {
	int a;
	double d;
	char c;
};
int main() {
	str *p = new str{3,9.003,'s'};
	cout << (*p).d << '\n';
	cout << (*p).a << '\n';
	cout << (*p).c << '\n';
}
