#ifndef INPUT_PROCESSOR_H
#define INPUT_PROCESSOR_H

#include<iostream>
#include<string>
#include<string_view>
using std::cin, std::string, std::cout, std::string_view;

void inputValue( int &toInput, string_view prompt="none");

void inputValue( string &toInput, string_view prompt="none");

void inputValue( double &toInput, string_view prompt="none");

void inputValue( char &toInput, string_view prompt="none");

void inputArray( const int &size, int * toInput, string_view prompt="none"); 

void inputArray( const int &size, string * toInput, string_view prompt="none");

void inputArray( const int &size, double * toInput, string_view prompt="none");

void inputArray( const int &size, char * toInput, string_view prompt="none");

#endif
