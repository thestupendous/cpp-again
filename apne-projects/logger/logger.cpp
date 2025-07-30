// currently logs only to console

#include<string>
#include<iostream>
#include<string_view>
using std::string, std::cout, std::string_view;

// log levels
//     i - info 
//     c - critical 
//     d - debug
//     w - warning
//     e - error
#include "logger.h"
#include <string>
using std::string;

void log(const string_view & message, const string_view & logLevel, int indLvl) {
	string indent = "  ";
	while (--indLvl) {
		indent += "  ";
	}

	cout << indent ;
	cout << logLevel ;
	cout << ": " << message << '\n';
}

// just for testing, this func needs to be removed
int main() {
	log("alkfds","i",2);
	log("alkfds","i",3);
	log("","i",4);
	log("alkfds","i");

	return 0;
}

