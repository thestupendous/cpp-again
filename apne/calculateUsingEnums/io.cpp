#include<iostream>
#include "dataStructures.h"
#include "operations.h"
void printObject(const Out& response)
{	
	using std::cout, std::endl;
	if ( response.err == SUCCESS ) 
	{
		cout << response.res << endl;
	}
	else
	{
		cout << "Error mila : " << getError(response.err) << endl;
	}
}

