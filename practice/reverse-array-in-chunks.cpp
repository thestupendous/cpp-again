/*
	 Given an array arr[] and an integer k, the task 
	 is to reverse every subarray formed by 
	 consecutive K elements.
	 problem link - https://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
*/

#include <iostream>
#include <vector>
#include <cstdint>

void print(std::vector<int> &arr) {
	for (auto i {arr.begin()} ; i!=arr.end() ; i++ ) {
		std::cout << *i << ',';
	}
	std::cout << '\n';
}

void swap (int &a,int &b) {
	int c = a;
	a = b;
	b = c;
}

void reverseInChunks(std::vector<int> &arr, int k) {
	if (k <= 1) return;
	uint_fast32_t evenLen { arr.size() - ( arr.size()%3 ) } ;

	// Simple reverse
	for ( uint_fast32_t i {0} ; i < k/2 ; i++ ) {
		for ( uint_fast32_t j {0} ; j<evenLen ; j += k ) {
			swap ( arr[j+i], arr[j+k-i-1] );
		}
	}

	// reverse baaki array
	for ( uint_fast32_t i { evenLen } ; i < ( arr.size()-1 )/2 ; i++ ) {
			swap ( arr[i], arr[k-i-1] );
	}

}

int main() {
	std::vector<int> arr { 
		1,2,3, 
		0,20,40, 
		-2,-11,-90, 
		777,3 };
	
	print(arr);

	reverseInChunks(arr,3);

	print(arr);

	return 0;
}

