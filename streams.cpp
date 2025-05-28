#include <fstream>
#include <iostream>
using namespace std;

int main() {
	// file
	ifstream ip("input.txt");
	int a,b,c;
	ip >> a;
	ip >> b;
	ip >> c;
	cout << "Raam Raam\n" << a << ',' << b << ',' << c << '\n';
	ip.close();

	ofstream ou("output.txt");
	ou << a;
	ou << b;
	ou << c;
	ou.close();

	struct shoe{
		string make;
		unsigned size;
	};

	// Binary files
	shoe s1 { "adidas", 5 };
	shoe s2 { "rebook", 4 };
	ofstream ou2("input-bin.txt",ios::binary);
	ou2 << a;
	ou2 << b;
	ou2 << c;
	ou2 << s1;
	ou2 << s2;
	ou2.close();

	ifstream ip2("input-bin.txt",ios::binary);
	a = 0,b = 0,c = 0;
	shoe s3,s4;
	ip2 >> a;
	ip2 >> b;
	ip2 >> c;
	ip2 >> s3;
	cout << "Raam Raam\n" << a << ',' << b << ',' << c << '\n';
	cout << "Raam Raam\n" << s3.make  << s3.size  << '\n';
	ip2.close();

	return 0;
}

