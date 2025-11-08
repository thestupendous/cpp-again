#include <iostream>
#include <vector>
#include <string>
using std::string,std::cout, std::vector;

struct man{
	string name;
	unsigned age;
};

int main() {
	vector<man*> v(4);
	for (man* m: v) {
		if ( m == nullptr) cout << "nullptr\n";
		if ( m == 0) cout << "0\n";
	}
	return 0;
}
