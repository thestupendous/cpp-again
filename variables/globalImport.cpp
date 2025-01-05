#include <iostream>

extern const double g_pi;
extern const int  g_maxAge;
extern int  g_time;
//extern const int g_x;

int main()
{
	using std::cout;

	//cout << g_x << '\n';
	
	cout << g_pi << '\n';

	cout << g_maxAge << '\n';
	cout << g_time << '\n';


	return 0;
}
