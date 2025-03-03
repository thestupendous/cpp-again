#include "complex.h"

std::string Complex::get() const {
	if (imag > 0) {
		return std::to_string(real) + " + " + std::to_string(imag) + "i";
	} else if (imag < 0) {
		return std::to_string(real) + " - " + std::to_string(-imag) + "i";
	} else {
		return std::to_string(real) + " + 0i";
	}

}

Complex Complex::add(const Complex &b) {
	return Complex { real+b.real , imag+b.imag };
}

Complex Complex::subtract(const Complex &b) {
	return Complex { real-b.real , imag-b.imag };
}

Complex Complex::divide(const Complex &b) {
	double re = ( real*b.real + imag*b.imag ) /
		( b.real*b.real + b.imag*b.imag ) ;
	double im = ( imag*b.real - real*b.imag ) /
		( b.real*b.real + b.imag*b.imag ) ;
	return Complex { re , im };
}

Complex Complex::multiply(const Complex &b) {
	return Complex { 
		real*b.real - imag*b.imag,
		real*b.imag + imag*b.real
	};
}
