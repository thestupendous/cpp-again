#include <cstdint>
#include <iostream>
#include <limits>
using std::cout;

int main(){
  cout << "int minimum " << std::numeric_limits<int>::min() <<'\n';
  cout << "int minimum " << std::numeric_limits<int>::lowest() <<'\n';
  cout << "double max " << std::numeric_limits<double>::max() <<'\n';

  uint64_t maxDouble = static_cast<uint64_t>(std::numeric_limits<double>::max());
  cout << maxDouble <<'\n';

  return 0;
}
