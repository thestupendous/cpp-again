#include<iostream>
#include<string_view>
#include<string>
using std::cout,std::string,std::string_view;

int main(int num, char **arr) {

	cout << "cmd args are " << '\n';
  //string_view word;
	for (int i{0}; i<num; i++  ) {
		cout << *(arr+i) << ", ";
	}
	cout << '\n';

	return 0;
}
