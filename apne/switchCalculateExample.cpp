/*
 * Write a function called calculate() that takes two integers and a char representing
 * one of the following mathematical operations: +, -, *, /, or % (remainder). Use a switch
 * statement to perform the appropriate mathematical operation on the integers,
 * and return the result. If an invalid operator is passed into the function, the
 * function should print an error message. For the division operator, do an integer
 * division, and don’t worry about divide by zero.
 */

#include "../standardHeader.h"

enum Error {
	SUCCESS, DIVISIONBYZERO, INVALIDOPERATION
};

struct Out {
	double res;
	Error err;
};

constexpr string_view getError(Error e)
{
	switch (e)
	{
		case DIVISIONBYZERO:
			return "trying to divide by zero";
		case INVALIDOPERATION:
			return "Invalid operation argument provided";
		default:
			return "not possible";
	}
}

void printObject(const Out& response)
{	
	if ( response.err == SUCCESS ) 
	{
		cout << response.res << endl;
	}
	else
	{
		cout << "Error mila : " << getError(response.err) << '\n';
	}
}


Out calculate(int n1,int n2,char op)
{
	Out o;
	o.res = -999999;
	o.err = SUCCESS;

	switch(op)
	{
	case '+':
		o.res = n1+n2;
		return o;
	case '-':
		o.res = n1-n2;
		return o;
	case '*':
		o.res = n1*n2;
		return o;
	case '/':
		if ( n2==0 ) {
			o.err = DIVISIONBYZERO;
			return o;
		}
		o.res = (static_cast<double> (n1) )/n2;
		return o;
	default:
		o.err = INVALIDOPERATION;
		return o;
	}
}

int main()
{
	Out response;
	// pehla
	response = calculate(7,3,'/');
	printObject(response);

	// dusra
	response = calculate(0,0,'/');
	printObject(response);
	
	return 0;
}






