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


    return 0;
}
