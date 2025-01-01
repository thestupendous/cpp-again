// fixed width integers **very helpful for portability, cross-platform development**
#include <cstdint> // for fixed-width integers, fast and least integers
#include <iostream>

/*
    std::int8_t	    1 byte signed	    -128 to 127
        Treated like a signed char on many systems. See note below.
    std::uint8_t	1 byte unsigned	    0 to 255
        Treated like an unsigned char on many systems. See note below.
    std::int16_t	2 byte signed	    -32,768 to 32,767	
    std::uint16_t	2 byte unsigned	    0 to 65,535	
    std::int32_t	4 byte signed	    -2,147,483,648 to 2,147,483,647	
    std::uint32_t	4 byte unsigned	    0 to 4,294,967,295	
    std::int64_t	8 byte signed	    -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807	
    std::uint64_t	8 byte unsigned	    0 to 18,446,744,073,709,551,615

*/
int main()
{
    std::int32_t x { 32767 }; // x is always a 32-bit integer
    x = x + 1;                // so 32768 will always fit
    std::cout << x << '\n';

    // std::uint8_t is often taken as char by compilers
    std::int8_t a { 65 };   // initialize 8-bit integral type with value 65
    std::cout << a << '\n'; // You're probably expecting this to print 65


    //fast and least integers
    std::cout << "least 8:  " << sizeof(std::int_least8_t)  * 8 << " bits\n";
	std::cout << "least 16: " << sizeof(std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof(std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  "  << sizeof(std::int_fast8_t)   * 8 << " bits\n";
	std::cout << "fast 16: "  << sizeof(std::int_fast16_t)  * 8 << " bits\n";
	std::cout << "fast 32: "  << sizeof(std::int_fast32_t)  * 8 << " bits\n";


    return 0;
}