/*
 * Curios thing - 
 *  - when I turn of #if block, i.e., when I remove the constructor,
 *    copy constructor, move constructor definitions, the program
 *    creates two separate copies for local function and for main,
 *    BUT as soon as I turn it on (define the constructors), it keeps
 *    having one and same struct for both main and local functions 🤔
	 */
#include<iostream>
using std::cout;

struct MaxVals {
	int maxSize;
	int maxArea;

#if 1
	MaxVals(const MaxVals &other) {
		cout << "copied to this obj!\n";
		maxSize = other.maxSize;
		maxArea = other.maxArea;
	}
	MaxVals(): maxSize{0},maxArea{0} {
		cout << "default constructor called!\n";
	}
	MaxVals(MaxVals &&other) noexcept {
		cout << "moved to this obj!\n";
		maxSize = other.maxSize;
		maxArea = other.maxArea;
	}
#endif
};

MaxVals getStruct() {
	MaxVals res;
	res.maxArea = 53420;
	res.maxSize = 290;

	cout << "address in local function " << &res << "\n";
	return res;
}

int main() {

	MaxVals res = getStruct();
	cout << "address in main " << &res << "\n";
	// the output of above means there are two different structs

	return 0;
}
