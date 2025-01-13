//#include <cereal/archives/json.hpp>
#include "Cust.h"
#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>
#include<fstream>
#include<iostream>
using std::cout;

using uli = unsigned long int;


int main()
{
	/*
	   Cust pehla;
	   pehla.add("Cyla",934234324,15342.34);
	   pehla.print();
	   */

	//std::ofstream file{"dukaan-register.json"}; // any stream can be used
	std::ofstream fileB("dukaan-register.bin", std::ios::binary); // any stream can be used

	//	cereal::JSONOutputArchive oarchive(file); // Create an output archive
		cereal::BinaryOutputArchive oarchiveB(fileB); // Create an output archive

		Cust m1("pro",99999999,99.99), m2("noob",1000001,101.101), m3;
	//	oarchive(m1, m2, m3); // Write the data to the archive
		oarchiveB(m1, m2, m3); // Write the data to the archive
	 // archive goes out of scope, ensuring all contents are flushed
	 // file.close();
	  fileB.close();

	//std::ifstream file2{"dukaan-register.json"}; // any stream can be used
	std::ifstream file2B("dukaan-register.bin",std::ios::binary); // any stream can be used
	//	cereal::JSONInputArchive iarchive(file2); // Create an input archive
		cereal::BinaryInputArchive iarchiveB(file2B); // Create an input archive

	//	Cust m4, m5, m6;
		Cust m7, m8, m9;
	//	iarchive(m4, m5, m6); // Read the data from the archive
		iarchiveB(m7, m8, m9); // Read the data from the archive
	//	m4.print();
	//	m5.print();
	//	m6.print();
		m7.print();
		m8.print();
		m9.print();
	 // file2.close();
	  file2B.close();

	return 0;
}
