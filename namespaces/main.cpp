//contains namespaces, multiple extensions of a namespace (in growth and cirlce headers extending BasicMath namespace),
//              --> scope of different methods being called from within a namespace

#include<iostream>
using namespace std;

#include "circle.h" // for BasicMath::pi
#include "growth.h" // for BasicMath::e
#include "add.h"
#include "main.h"


/// @brief 
void print(){
    cout<<"Hello\n";
}

namespace Foo
{
	/// @brief 
	void print() // this print() lives in the Foo namespace
	{
		std::cout << "Hello from foo\n";
	}

	/// @brief 
	void printHelloThere()
	{
		print();   // calls print() in Foo namespace
		::print(); // calls print() in global namespace
	}
}


int main(){

    print();
    Foo::printHelloThere();


    cout<< BasicMath::pi << endl;
    cout<< BasicMath::e << endl;

    cout<< BasicMath::add(3,10) << endl;



}