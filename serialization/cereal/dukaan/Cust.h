#include<iostream>
#include<string>
#include<string_view>
//#include<cereal>
using std::cout,std::cin,std::string,std::string_view;

using uli = unsigned long int;

class Cust //matlab customer
{
	string name;
	uli mobile;
	double kharcha;

	public:
	Cust():name(""),mobile(0),kharcha(0.0){}
	Cust(const string& name_,const uli& mobile_,const double& kharcha_)
	{
		name = name_;
		mobile = mobile_;
		kharcha = kharcha_;
	}
	template<class Archive>
	void serialize(Archive & archive)
	{
		archive( name, mobile, kharcha ); // serialize things by passing them to the archive
	}
	void add(string_view name,const uli mobile,const double kharcha);

	void print();

};
