/*
 * Given an array arr[] of size n, the task is to rearrange it in 
 * alternate positive and negative manner without changing the 
 * relative order of positive and negative numbers. In case of 
 * extra positive/negative numbers, they appear at the end of 
 * the array. The rearranged array should start with a 
 * positive number and 0 (zero) should be considered as a 
 * positive number.
 * link - https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/
*/

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

void print(const std::vector<int> &arr) {
	for (auto i {arr.begin()} ; i!=arr.end() ; i++ ) {
		std::cout << *i << ',';
	}
	std::cout << '\n';
}

void rearrange(vector<int> &arr) {
	vector<int> tem;
	for (int i{0};i<arr.size();i++){
		if ( arr[i]<0 ) {
			tem.push_back(arr[i]);
		}
	}
	int negLen { tem.size() };
	cout << "negative length : " << negLen ;

	for (int i{0};i<arr.size();i++){
		if ( arr[i] >= 0 ) {
			tem.push_back(arr[i]);
		}
	}
	int posLen { tem.size() };
	cout << "positive length : " << posLen ;

	cout << "temp : " ;
	print(tem);

	int i {0}, posI {negLen}, negI {0};
	while ( posI < posLen || negI < negLen ) {
		if ( posI < posLen ) {
			arr[i++] = tem[posI++];
		}
		if ( negI < negLen ) {
			arr[i++] = tem[negI++];
		}
	}

}

int main()
{
	vector<int> arr { -5,-2,5,2,4,7,1,8,0,-8 }; 
	cout << "input : " ;
	print(arr);
	rearrange(arr);
	cout << "result : " ;
	print(arr);
	return 0;
}
