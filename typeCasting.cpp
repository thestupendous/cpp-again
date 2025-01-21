// purane samaya `(int) x` ka use karke typecasting karte the,
// abhi `static_cast<int> x` ka use karke typecasting karte hain

#include <iostream>
void print(int x)
{
    std::cout << x << '\n';
}

int main()
{
    print(static_cast<int>(5.5)); // explicitly convert double value 5.5 to an int

    return 0;
}
