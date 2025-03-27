#include <iostream>
using std::cout;

class Simple {
public:
	int main() {
		cout << "Raam Raam, from simple main\n";
		return 0;
	}
};

int main(){
	Simple sm;

	sm.main();
	return 0;
}

