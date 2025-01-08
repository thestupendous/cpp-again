/*
 * We can tell the compiler that instantiation of function 
 * templates with certain arguments should be disallowed. This is done
 * by using function template specialization, which allow us to overload a
 * function template for a specific set of template arguments, along with = delete, 
 * which tells the compiler that any use of the function should emit a compilation error. 
 *
 */

#include <iostream>
#include <string>

template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
// const char* will match a string literal
template <>
const char* addOne(const char* x) = delete;

int main()
{
    std::cout << addOne("Hello, world!") << '\n'; // compile error

    return 0;
}
