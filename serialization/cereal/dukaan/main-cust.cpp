#include <cereal/archives/binary.hpp>
#include <sstream>

#include<iostream>
#include<string>
#include<string_view>
#include "Cust.h"
using std::cout,std::cin,std::string,std::string_view;

using uli = unsigned long int;


int main()
{
	/*
	   Cust pehla;
	   pehla.add("Cyla",934234324,15342.34);
	   pehla.print();
	   */

	std::stringstream ss; // any stream can be used

	{
		cereal::BinaryOutputArchive oarchive(ss); // Create an output archive

		Cust m1, m2, m3;
		oarchive(m1, m2, m3); // Write the data to the archive
	} // archive goes out of scope, ensuring all contents are flushed

	{
		cereal::BinaryInputArchive iarchive(ss); // Create an input archive

		Cust m1, m2, m3;
		iarchive(m1, m2, m3); // Read the data from the archive
	}

	return 0;
}
