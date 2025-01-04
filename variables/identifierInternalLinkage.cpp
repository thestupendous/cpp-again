/*
 * An identifier with internal linkage can be seen and used
 * within a single translation unit, but it is
 * not accessible from other translation units.
 * This means that if two source files have identically
 * named identifiers with internal linkage,
 * those identifiers will be treated as independent (and 
 * do not result in an ODR violation for having
 * duplicate definitions).
 */

#include <iostream>

static int g_x{}; // non-constant globals have external linkage by
				  // default, but can be given internal linkage 
				  // via the static keyword

const int g_y{ 1 }; // const globals have internal linkage by default
constexpr int g_z{ 2 }; // constexpr globals have internal linkage
						// by default

// This function is declared as static, and can now be used only 
// within this file
// Attempts to access it from another file via a function
// forward declaration will fail
[[maybe_unused]] static int add(int x, int y)
{
    return x + y;
}

int main()
{
    std::cout << g_x << ' ' << g_y << ' ' << g_z << '\n';
    return 0;
}

