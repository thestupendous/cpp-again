#include "dataStructures.h"
#include "operations.h"
#include "io.h"

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

