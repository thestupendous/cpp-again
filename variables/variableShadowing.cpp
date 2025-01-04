#include "standardHeader.h"

int val = 101;

int main()
{
	int apples (5);

	{
		cout << apples << '\n'; //bahar wala apples
								//
		int apples (0);	//defined apple in bheetar wala scope


		//shadowing of outer scope variable apples
		apples = 10; //applies to bheetar wale apples

		cout << apples << '\n'; //prints bheetar wala
		cout << apples << '\n'; //prints bheetar wala

	}

		cout << apples << '\n'; //prints bahar wala



		// overshadows global scope variable 'value'
		int val (7); 

		++val;

		cout << "local variable val : " << val << '\n';

		// agar global wala val access karna ho to
		// if we want to access global variable val
		cout << "global variable val : " << ::val << '\n';




		return 0;
}


















