//string_view gets rid of the 'expensive copies' that are made each time c++
	//strings are copied
//string_view is read only view of a string, c string literal, or string_view
//can be used as an argument to functions

#include <iostream>
#include <string_view> //c++17

// string_view provides read-only access to whatever argument is passed in
void printSV(std::string_view str)  // no copies are made of the string
{
    std::cout << str << '\n';
}

int main()
{
    std::string_view st{"Raam Raam bhai"}; // now an
                                          // std::string_view object
										  //
    
	//use of string_view - as parameter to functions
	printSV(st);

    std::string_view s1 { "raam raam bhai" }; // initialize
                                              // with C-style string literal
    std::cout << s1 <<'\n';

    std::string s {"Raam Raam bhai"};
    std::string_view s2 { s }; // initialize with std::string
    std::cout << s2 << '\n';

    std::string_view s3 { s2 }; // initialize with another
    // std::string_view
    std::cout << s3 << '\n';



    // assignment to string_view
    std::string name { "Alex" };
    std::string_view sv { name }; // sv is now viewing name
    std::cout << sv << '\n'; // prints Alex

    sv = "John"; // sv is now viewing "John" (does not change name)
    std::cout << sv << '\n'; // prints John

    std::cout << name << '\n'; // prints Alex
							   //
							   //
							   //
							   //

	// constexpr works with string_view
	constexpr std::string_view print_string{"Sabko Raam Raam!"};
				//print_string is now symbolic constant
	std::cout << print_string << '\n';
				//print_string will be replaced with "Sabko Raam Raam!"
				//at compile time
				//
	
	// Modifications to string_view
	std::string_view str{ "Peach" };
	std::cout << str << '\n';

	// Remove 1 character from the left side of the view
	str.remove_prefix(1);
	std::cout << "after removing 1st char from start " << str << '\n';

	// Remove 2 characters from the right side of the view
	str.remove_suffix(2);
	std::cout <<  "after removing 2 char from end " << str << '\n';

	str = "Peach"; // reset the view
	std::cout << "after resetting string_view " << str << '\n';

    return 0;
}
