#include <iostream>
#include <algorithm>
#include <array>


int main() {
	std::array<int,5> ar{1,4,2,3,-20};

/*
	for (auto element: ar) {
		std::cout << element << ',';
	}
	std::cout << '\n';
*/

	// lambda syntax
	// [ captures ] ( params ) specs requires (optional) { body }

	std::for_each(begin(ar),
			end(ar), 
			[](int n) {
				std::cout << n << ',';
			});

	return 0;
}


