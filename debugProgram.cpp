#include <iostream>
int k=3;
void printValue(int value)
{
    std::cout << value << '\n';
    k=10;
}

int main()
{
    k=423;
    std::cout << std::unitbuf; // enable automatic flushing for std::cout (for debugging)
    printValue(5);

    return 0;
}