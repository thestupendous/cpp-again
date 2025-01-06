/*
 * If the constexpr conditional evaluates to true, the entire if-else 
 * will be replaced by the true-statement. If the constexpr conditional 
 * evaluates to false, the entire if-else will be replaced by the 
 * false-statement (if it exists) or nothing (if there is no else).
 *
 * use constexper if statements when condition is constant
 */

#include <iostream>
int main()
{
	// basic example
    std::cout << "Enter 0 or 1: ";
    int x{};
    std::cin >> x;
    if (x = 0) // oops, we used an assignment here instead of a test for equality
        std::cout << "You entered 0\n";
    else
        std::cout << "You entered 1\n";



	// constexper in if-else
	constexpr double gravity{ 9.8 };
			// reminder: low-precision floating point literals of the 
			// same type can be tested for equality
	if (gravity == 9.8) // constant expression, always true
		std::cout << "Gravity is normal.\n";   // will always be executed
	else
		std::cout << "We are not on Earth.\n"; // will never be executed

	// constexpr if statement
	if constexpr (gravity == 9.8) // now using constexpr if
		std::cout << "Gravity is normal.\n";
	else
		std::cout << "We are not on Earth.\n";
    return 0;
}
