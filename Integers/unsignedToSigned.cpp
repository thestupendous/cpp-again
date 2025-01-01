// This program shows why signed and unsigned integers should not be
// mixed in comparisons or expressions.
#include <iostream>

int main()
{
    unsigned short x{0}; // smallest 2-byte unsigned value possible
    std::cout << "x was: " << x << '\n';

    x = -1; // -1 is out of our range, so we get modulo wrap-around
            // this generates a warning
    std::cout << "x is now: " << x << '\n';

    x = -2; // -2 is out of our range, so we get modulo wrap-around
            // this generates a warning
    std::cout << "x is now: " << x << '\n';

    // unsigned int s{-1}; // -1 is implicitly converted to 4294967295
    signed int s{-1};
    unsigned int u{1};

    if (s < u) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
        std::cout << "-1 is less than 1\n";
    else
        std::cout << "1 is less than -1\n"; // this statement executes
    return 0;
}