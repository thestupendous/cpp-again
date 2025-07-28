#include <iostream>
#include <string>
using std::cout, std::string;
#include "input-processor.h"

int main() {
	int a,b;
	inputValue(a);
	inputValue(b);

	cout << a << ',' << b << '\n';

	string names[5];
	inputArray(5,names,"names plz: ");

	cout << names[2] << '\n';


	return 0;
}
