#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>
#include <climits> // for CHAR_BIT
#include <string>

void print(std::string str, std::string str2)
{
    std::cout << str << " : " << str2 << std::endl;
}

int main()
{
#if 1
    std::cout << "A byte is " << CHAR_BIT << " bits\n\n";

    std::cout << std::left; // left justify output

    std::cout << std::setw(16) << "bool:" << sizeof(bool) << " bytes\n";
    std::cout << std::setw(16) << "char:" << sizeof(char) << " bytes\n";
    std::cout << std::setw(16) << "short:" << sizeof(short) << " bytes\n";
    std::cout << std::setw(16) << "int:" << sizeof(int) << " bytes\n";
    std::cout << std::setw(16) << "long:" << sizeof(long) << " bytes\n";
    std::cout << std::setw(16) << "long long:" << sizeof(long long) << " bytes\n";
    std::cout << std::setw(16) << "float:" << sizeof(float) << " bytes\n";
    std::cout << std::setw(16) << "double:" << sizeof(double) << " bytes\n";
    std::cout << std::setw(16) << "long double:" << sizeof(long double) << " bytes\n";

    print("int min", std::to_string(INT_MIN));
    print("int max", std::to_string(INT_MAX));
    print("long min", std::to_string(LONG_MIN));
    print("long max", std::to_string(LONG_MAX));
#endif
    int x;
    std::cin >> x; // try entering a number larger than 2147483647
    // int y = 9999999999;
    print("how is x : ", std::to_string(x));
    // print("how is y : ", std::to_string(y));

    // another case of an overflow
    //  assume 4 byte integers
    int j{2'147'483'647}; // the maximum value of a 4-byte signed integer
    std::cout << j << '\n';

    j = j + 1; // integer overflow, undefined behavior
    std::cout << j << '\n';

    return 0;
}
