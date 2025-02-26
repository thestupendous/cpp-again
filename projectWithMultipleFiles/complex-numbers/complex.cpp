#include "complex.h"

std::string Complex::get() const {
			return std::to_string(real) + " + " + std::to_string(imag) + "i";
}

Complex Complex::add(const Complex &b) {
	return Complex { real+b.real , imag+b.imag };
}

Complex Complex::subtract(const Complex &b) {
	return Complex { real-b.real , imag-b.imag };
}

//TODO not accurate
Complex Complex::divide(const Complex &b) {
	return Complex { real-b.real , imag-b.imag };
}

//TODO not accurate
Complex Complex::multiply(const Complex &b) {
	return Complex { real-b.real , imag-b.imag };
}
