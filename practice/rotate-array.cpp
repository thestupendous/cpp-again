/*
	 2 ways to do the operation are implemented!
	 with and without extra array

	 Given an array of integers arr[] of size n, 
	 the task is to rotate the array elements to 
	 the left by k positions.
	 link - https://www.geeksforgeeks.org/array-rotation/
*/

#include <iostream>
#include <vector>
#include <cstdint>
using std::cout;
void print(std::vector<int> &arr) {
	for (auto i {arr.begin()} ; i!=arr.end() ; i++ ) {
		std::cout << *i << ',';
	}
	std::cout << '\n';
}

void rotateArr(std::vector<int> &arr, uint_fast32_t k) {
	k = k%(arr.size());
  std::vector<int> tem; 
	// move till k to tem
	for ( uint_fast32_t i {0} ; i<k ; i++ ) {
		tem.push_back( arr[i] );
	}
	// cout << "tem : " ;
	print(tem);

	// shift arr
	for ( uint_fast32_t i {k}, j {0} ; i < arr.size() ; i++, j++ ) {
		arr[j] = arr[i];
	}
	// cout << "2nd : " ;
	// print(arr);

	// move copied elements to last
	for ( uint_fast32_t i { arr.size() - k } , j {0}  ; i<arr.size() ; i++,j++ ) {
		arr[i] = tem[j];
	}
}

void reverseArr(std::vector<int> &arr, uint_fast32_t start, uint_fast32_t end) {
	int tem;
	if (start>arr.size() || end<=0 || start>=end) {
		cout << "Error in reversing!\n";
		return;
	}
	while (start<end) {
		tem = arr[start];
		arr[start++] = arr[end];
		arr[end--] = tem;
	}
}

void rotateArrBinaTem(std::vector<int> &arr, uint_fast32_t k) {
	if (k<=1) return;
	k %= arr.size();

	// reverse shuru
	reverseArr(arr,0,k-1);

	// reverse baki
	reverseArr(arr,k,arr.size()-1);

	// reverse saara firse
	reverseArr(arr,0,arr.size()-1);

}

int main() {
	std::vector<int> arr { 1,2,3,4,5,6,7 };
	print(arr);
	rotateArr(arr,3);
	print(arr);

	cout << "ab bina extra array k\n";
	std::vector<int> arr2 { 1,2,3,4,5,6,7 };
	print(arr2);
	rotateArrBinaTem(arr2,3);
	print(arr2);

	return 0;
}
