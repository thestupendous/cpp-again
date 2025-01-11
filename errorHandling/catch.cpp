#include<iostream>
using std::cout;
using std::cin;

int main()
{
	int x,y;
	cin >> x >> y;

	double div (0.);

	div = x / static_cast<double>(y) ;
	cout << div << '\n';
	div++;
	cout << div << '\n';

#if 0
	try {
		div = x / static_cast<double>(y) ;
		cout << div << '\n';
	}
	catch (const char* msg)
	{
		cout <<"Bhai Error aagaya, ye dekh le -> [ "<<msg<<" ] , Theek kar lena\n";
	}
#endif
	return 0;
}

