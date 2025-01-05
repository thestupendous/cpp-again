#include "pi2.h" // will include copy of pi() here
#include <iostream>
double circumference(double radius); // forward declaration
int main()
{
	using  std::cout;
	cout << pi() << '\n';
	cout << circumference(4.) << '\n';
	return 0;
}
