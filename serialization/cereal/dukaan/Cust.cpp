#include "Cust.h"


void Cust::add(string_view name_,const uli mobile_,const double kharcha_)
{
	this->name = name_;
	this->mobile = mobile_;
	this->kharcha = kharcha_;
}

void Cust::print()
{
	cout << mobile << ',' << name  << ','<< kharcha << '\n';
}

