#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void maxMin(const vector<int> &vec){
	int max{std::numeric_limits<int>::min()};
	int min{std::numeric_limits<int>::max()};

	for (auto i{vec.begin()} ; i<vec.end() ; i++ ) {
		if (max < *i) max = *i;
		else if (min > *i) min = *i;
	}
	
	cout << "max" << ' ' << max << '\n';
	cout << "min" << ' ' << min << '\n';

}


int main() {
	vector<int> vec { 3,4,25,239,-234,34,9800 };
	
	maxMin(vec);

	return 0;
}

