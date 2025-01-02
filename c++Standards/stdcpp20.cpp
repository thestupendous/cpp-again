// checking if compiler can run c++20 code

/*
	"-fdiagnostics-color=always",
                "-ggdb",
                "-pedantic-errors", // disable compiler extensions
                "-Wall", //next 5 lines, increase warning levels
                "-Weffc++",
                "-Wextra",
                "-Wconversion",
                "std=c++20",
                "-Wsign-conversion",
                "-Werror", //treat all warnings as errors
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
*/

#include <iostream>
#include<vector>
#include <compare>
using namespace std;

// Driver Code
int main()
{
	int a = 91, b = 110;
	auto ans1 = a <=> b;

	if (ans1 < 0) {
		cout << "a < b\n";
	}
	else if (ans1 == 0) {
		cout << "a == b\n";
	}
	else if (ans1 > 0) {
		cout << "a > b\n";
	}

	vector<int> v1{ 3, 6, 9 };
	vector<int> v2{ 3, 6, 9 };
	auto ans2 = v1 <=> v2;

	if (ans2 < 0) {
		cout << "v1 < v2\n";
	}
	else if (ans2 == 0) {

		cout << "v1 == v2\n";
	}
	else if (ans2 > 0) {

		cout << "v1 > v2\n";
	}

	cout << endl;
}
