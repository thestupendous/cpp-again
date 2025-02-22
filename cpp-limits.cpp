#include <cstdint>
#include <iostream>
#include <limits>
#include<vector>
using namespace std;

void maxMin(const vector<int> &vec){
	int max{std::numeric_limits<int>::min()};
	int min{std::numeric_limits<int>::max()};


}


int main() {
	vector<int> vec;
	
	maxMin(vec);

	return 0;
}

using std::cout;

int main(){
  cout << "int minimum " << std::numeric_limits<int>::min() <<'\n';
  cout << "int minimum " << std::numeric_limits<int>::lowest() <<'\n';
  cout << "double max " << std::numeric_limits<double>::max() <<'\n';

  uint64_t maxDouble = static_cast<uint64_t>(std::numeric_limits<double>::max());
  cout << maxDouble <<'\n';

  return 0;
}
