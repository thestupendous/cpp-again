// TODO: POORA KARNA H, not complete
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

template <typename T>
T addOne(T x)
{
    return x + 1;
}

// Use function template specialization to tell the compiler that addOne(const char*) should emit a compilation error
// const char* will match a string literal
//template <>
//const char* addOne(const char* x) = delete;

string print(const string_view s)
{
	cout << '[' << s << ']';
	return static_cast<string>(s);
}

int main()
{
    std::cout << addOne("Hello, world!"s) << '\n'; // compile error
    std::cout << print("Hello, world!"s) << '\n'; 

    return 0;
}
