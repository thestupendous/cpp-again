#include<iostream>
#include<array>
using std::cout;

void printArray(std::array<int,5> arr) {
	//cout << "arr.size()\t\t: " << arr.size() << '\n';
	//cout << "Sizeof (in bytes) \t: " << sizeof(arr) << '\n';


	// for (int i=0; i<arr.size() ; i++) {
	// 	cout << arr.at(i) << ',' ;
	// }
	// cout << '\n';

	// for ( auto i=arr.begin() ; i != arr.end() ; i++ ) {
	// 	cout << *i << ',' ;
	// }
	// cout << '\n';

	for (auto i : arr) {
		cout << i << ',' ;
	}
	cout << '\n';

}


void legacyCStyleArrayProcessing( int * arr, int size) {
	cout << "In legacy C style processing\n";
	//----printing----
	for (int i{0} ; i<size ; i++) {
		cout << *(arr+i) << ':';
	}
	cout << '\n';

}

int main() {
	std::array<int,5> arr = {1,2,3,4,5};

	printArray(arr);


	cout << "arr[3]\t\t: " << arr.at(3) << '\n';
	cout << "arr[0]\t\t: " << arr[0] << '\n';


	//-----------fill---------
	arr.fill(1);
	printArray(arr);

  legacyCStyleArrayProcessing(arr.data(),5);

	return 0;
}

