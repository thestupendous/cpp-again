#include<iostream>
#include<string>
#include<string_view>
using std::cout,std::cin,std::string,std::string_view;

using uli = unsigned long int;

class Cust //matlab customer
{
	string name;
	uli mobile;
	double kharcha;
	public:
	
	void add(string_view name,const uli mobile,const double kharcha)
	{
		this->name = name;
		this->mobile = mobile;
		this->kharcha = kharcha;
	}

	void print()
	{
		cout << mobile << ',' << name  << ','<< kharcha << '\n';
	}

};

int main()
{
	Cust pehla;

	pehla.add("Cyla",934234324,15342.34);

	pehla.print();

	return 0;
}




	
