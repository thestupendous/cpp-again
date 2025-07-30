#ifndef LOGGER_H
#define LOGGER_H

#include<iostream>
#include<string_view>
using std::cout, std::string_view;

void log(const string_view & message,
		const string_view & logLevel, int indLvl=1);

#endif
