#include<iostream>
#include<array>
#include<cstdint>
using namespace std;

string areArraysEqual(const array<int,5> &arr1,const array<int,5> &arr2 ){
	for (uint32_t i{0} ; i < arr1.size() ; i++ ) {
		if (arr1.at(i) != arr2.at(i) ) return "false";
	}
	return "true";
}

int main() {
	array<int,5> arr1{1,2,3,4,5};
	array<int,5> arr2{1,2,3,4,5};


	cout << areArraysEqual(arr1,arr2) << '\n';

	arr1.at(2) = 100;

	cout << areArraysEqual(arr1,arr2) << '\n';
	

	return 0;
}

