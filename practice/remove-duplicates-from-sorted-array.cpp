/*
 * Given a sorted array arr[] of size n, the goal is to rearrange 
 * the array so that all distinct elements appear at the 
 * beginning in sorted order. Additionally, return the length 
 * of this distinct sorted subarray.
 * link - https://www.geeksforgeeks.org/remove-duplicates-sorted-array/
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

void removeDuplicates(vector<int> &arr) {
	if (arr.size() < 2 ) return;

	unsigned int j{0}, count {0};
	int prev { arr[0] };
	arr[j++] = arr[0];
	for (unsigned int i{1};i<arr.size();i++) {
		if (arr[i] != prev) {
			arr[j++] = arr[i];
			prev = arr[i];
		}
	}
}

int main()
{
	vector<int> arr { 1,1,1, 2,2, 3,3,3,3, 4,5,5, }; 
	removeDuplicates(arr);
	print(arr);
	return 0;
}
