//namespace x.y.z.meranamespace; // not working
namespace meranamespace
{
	int year(2025);

	int findOld(int year)
	{
		return meranamespace::year - year;
	}
};

#include<iostream>
using std::cout;
int main()
{
	cout << meranamespace::findOld(1999) << '\n';
	return 0;
}
