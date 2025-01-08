#include <iostream>
using namespace std;

template <typename T>
T max_non_std( T x, T y )
{
	return ( x < y ) ? y : x;
}

int main()
{
	cout << max_non_std(3,200) << '\n';
	cout << max_non_std(5.3,5.63) << '\n';
	cout << max_non_std('A','P') << '\n';
	cout << max_non_std("compiler","pile") << '\n';


	return 0;
}
