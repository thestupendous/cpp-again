#include <iostream>
#include "complex.h"

int main() {
	Complex a{8,3}, b{5,-2};

	std::cout << a.get() << '\n';
	std::cout << b.get() << '\n';


	
	std::cout << "+ is : " << (a.add(b)).get() << '\n';
	std::cout << "- is : " << (a.subtract(b)).get() << '\n';
	std::cout << "x is : " << (a.multiply(b)).get() << '\n';
	std::cout << "÷ is : " << (a.divide(b)).get() << '\n';

	return 0;
}
