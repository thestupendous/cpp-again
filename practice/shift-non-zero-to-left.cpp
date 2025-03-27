/*
	 shift all non zero elements in array to left without 
	 disturbing elements' order 
*/
#include <iostream>
#include <array>
#include <cstdint>
using namespace std;

#define AR_SIZE 8

void print(std::array<int,AR_SIZE> &arr) {
	for (auto i {arr.begin()} ; i!=arr.end() ; i++ ) {
		std::cout << *i << ',';
	}
	std::cout << '\n';
}

int main(){

	using std::cout;

	std::array<int,AR_SIZE> arr { 1,2,0,4,3,0,5,0 };
	print(arr);
  uint_fast32_t count {0};
	// shifting all to left
	for (uint_fast32_t i {0} ; i<AR_SIZE ; i++) {
		cout << i << ' ';

		if ( arr.at(i) != 0 ) {
			cout << "got " << arr.at(i) ;
			arr[count] = arr.at(i);
			++count;
		} else {
			;
		}
		cout << '\n';
	}
	cout << "count of non zero numbers " << count << '\n';
	print(arr);

	// deleting saare right side wale, setting to zero
	for (uint_fast32_t i {count} ; i<AR_SIZE ; i++) {
		arr[i] = 0;
	}
	print(arr);

	return 0;
}
