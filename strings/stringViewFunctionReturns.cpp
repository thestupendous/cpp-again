/*
 *	c string literals, have scope throughout the program
 *		does not matter where they are defined.
 *	Thus, string_view can be used from within functions to
 *		return c string literals as they have scope throughout program
*/
#include<iostream>
#include<string_view>

enum Time {
		morning,
		noon,
		evening,
		midnight,
		night
};

std::string_view greet(Time time){
	if (time == morning)
		return "Suprabhaat!";
	else if (time == evening)
		return "Shub Sandhya!";
	else
		return "Raam Raam ji!";
}

int main()
{
	using std::cout;
	Time abhi( morning );
	Time dasGhanteBaad( night );
	cout << greet(abhi) << '\n';
	cout << greet(dasGhanteBaad) << '\n';

	return 0;
}
