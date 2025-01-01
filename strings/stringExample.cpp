
#include <iostream>
#include <string> // For std::string and std::getline

int main()
{
    std::cout << "Enter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name); // read a full line of text into name

    std::cout << "Enter your favorite color: ";
    std::string color{};
    std::getline(std::cin >> std::ws, color); // read a full line of text into color

    std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

    // std::string literals
    using namespace std::string_literals; // easy access to the s suffix
    std::cout << "foo\n";                 // no suffix - is a C-style string literal
    std::cout << "joo\n"s;                // s suffix - is a std::string literal

    return 0;
}