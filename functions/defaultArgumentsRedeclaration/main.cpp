#include<iostream>
#include "headers.h"

double circumference(double radius, double pi)
{
	return ( 2 * pi * radius );
}

int main()
{

	using std::cout;
	cout << circumference(5) << '\n';
	cout << circumference(5.1) << '\n';
	cout << circumference(12) << '\n';

	return 0;
}
