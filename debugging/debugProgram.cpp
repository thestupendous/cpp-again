#include <iostream>

#if 0
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
#endif

#if 0 //for watching variables
int p=9;
int main()
{
    p=100;
	int x{ 1 };
	std::cout << x << ' ';

	x = x + 2;
	std::cout << x << ' ';

	x = x + 3;
	std::cout << x << ' ';

    p=200;

	return 0;
}
#endif

#if 1  //for examining call stack

void a()
{
	std::cout << "a() called\n";
}

void b()
{
	std::cout << "b() called\n";
	a();
}

int main()
{
	a();
	b();

	return 0;
}

#endif