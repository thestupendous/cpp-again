#include "Cust.h"


void Cust::add(string_view name,const uli mobile,const double kharcha)
{
	this->name = name;
	this->mobile = mobile;
	this->kharcha = kharcha;
}

void Cust::print()
{
	cout << mobile << ',' << name  << ','<< kharcha << '\n';
}

