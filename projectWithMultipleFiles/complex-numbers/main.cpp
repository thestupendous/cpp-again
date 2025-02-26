#include <iostream>
#include "complex.h"

int main() {
	Complex a{2,3}, b{10,-300};

	std::cout << a.get() << '\n';
	std::cout << b.get() << '\n';


	
	std::cout << "sum is : " << (a.add(b)).get() << '\n';

	return 0;
}
