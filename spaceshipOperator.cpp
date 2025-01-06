//compile me ye arg lagani h - `-std=c++23`
#include <algorithm>
#include <compare>
#include <cmath>
#include <iostream>
#include <string>

struct CaseInsensitiveString {
    std::string str;

    auto operator<=>(const CaseInsensitiveString& other) const {
        return std::lexicographical_compare_three_way(
            str.begin(), str.end(),
            other.str.begin(), other.str.end(),
            [](char a, char b) {
                return std::tolower(a) <=> std::tolower(b);
            }
        );
    }
};


int main() {

	//for strong ordering
	int x = 10;
	int y = 20;
	auto res = x <=> y;

	if (res < 0)
	std::cout << "Less\n";
	else if (res > 0)
	std::cout << "Greater\n";
	else if (res == 0)
	std::cout << "Same\n";
	else
	std::cout << "Unordered\n";

	//for weak ordering
	CaseInsensitiveString s1{"Hello"};
    CaseInsensitiveString s2{"hello"};
    CaseInsensitiveString s3{"World"};

    std::cout << std::boolalpha;
    std::cout << "s1 == s2: " << (s1 <=> s2 == 0) << std::endl;
    std::cout << "s1 < s3: " << (s1 <=> s3 < 0) << std::endl;

	//for partial ordering
    double a = 5.0;
    double b = std::nan("1");

    auto result = a <=> b;

    if (result < 0)
        std::cout << "a is less than b" << std::endl;
    else if (result > 0)
        std::cout << "a is greater than b" << std::endl;
    else if (result == 0)
        std::cout << "a is equal to b" << std::endl;
    else
	{
        std::cout << "a and b are unordered" << std::endl;
		std::cout << "\tand result is " << std::to_string(sizeof(result)) << '\n';
	}
	return 0;
}
