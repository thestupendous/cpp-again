#include <iostream>


#if 0 // this was the code before debugging and finding out the problem
int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x {};
	readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);

	return 0;
}
#endif

#if 1	//this is the code after debugging and fixing it
void readNumber(int& a)
{
	std::cout << "Please enter a number: ";
	std::cin >> a;
}

void writeAnswer(int b)
{
	std::cout << "The sum is: " << b << '\n';
}

int main()
{
	int x {},y{};
	readNumber(x);
	readNumber(y);
	x = x + y;
	writeAnswer(x);

	return 0;
}
#endif