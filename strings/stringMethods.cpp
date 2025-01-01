#include <iostream>
#include <string>

int main()
{
    std::string name{"Amrita"};
    std::cout << name << " has " << name.length() << " characters\n";

    // typical use of static_cast
    int length{static_cast<int>(name.length())};

    // caution! only use with c++20,
    // std::ssize() returns large signed integral type (usually std::ptrdiff_t)
    // std::cout << name << " has " << std::ssize(name) << " characters\n";

    return 0;
}