#include "dataStructures.h"
#include<string_view>

constexpr std::string_view getError(Error e)
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

