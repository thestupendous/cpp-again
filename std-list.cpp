#include<iostream>
#include<list>
using std::cout, std::list;


int main() {
	list<int> list1;
	list1.push_back(1);
	list1.push_back(2);
	list1.push_back(3);
	cout << list1.front() << '\n';

	return 0;
}
