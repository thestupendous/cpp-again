/*
 * Write a function called calculate() that takes two integers and a char representing
 * one of the following mathematical operations: +, -, *, /, or % (remainder). Use a switch
 * statement to perform the appropriate mathematical operation on the integers,
 * and return the result. If an invalid operator is passed into the function, the
 * function should print an error message. For the division operator, do an integer
 * division, and don’t worry about divide by zero.
 */

#include "standardHeader.h"

double calculate(int n1,int n2,char op)
{
	double res(0.0);
	switch(op)
	{
	case '+':
		res = n1+n2;
		return res;
	case '-':
		res = n1-n2;
		return res;
	case '*':
		res = n1*n2;
		return res;
	case '/':
		res = (static_cast<double> (n1) )/n2;
		return res;
	default:
		cout << "wrong option parameter\n";
		return -999999;
	}
}

int main()
{

	cout << calculate(7,3,'/') << endl;
	cout << calculate(9,2,'*') << endl;

	return 0;
}






