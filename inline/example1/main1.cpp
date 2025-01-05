#include <iostream>

double circumference(double radius); //forward decl

inline double pi() { return 3.14234; }

int main()
{
	using std::cout;
	cout << "pi " << pi() << '\n';
	cout << "circumference " << circumference(2.0) << '\n';

	return 0;
}
