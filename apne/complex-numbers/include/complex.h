#ifndef COMPLEX_H
#define COMPLEX_H

#include <string>

class Complex {
public:
	double real;
	double imag;

public:
	Complex(){}
	Complex(double r,double i=0):
		real{r},imag{i}
	{}

	std::string get() const;

	// friend add(const Complex &a,const Complex &b); 
	// friend subtract(const Complex &a,const Complex &b); 
	// friend divide(const Complex &a,const Complex &b); 
	// friend add(const Complex &a,const Complex &b); 

	Complex add(const Complex &b) ;
	Complex subtract(const Complex &b) ;
	Complex divide(const Complex &b) ;
	Complex multiply(const Complex &b) ;
};

#endif
