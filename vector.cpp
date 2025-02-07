#include <iostream>
#include <vector>
#include <cstdint>

using std::cout, std::vector;

int main() {
  vector <int> a {3,4,5,6,7,8,9,10};

  uint8_t index = 3;
  a.erase(a.begin() + index);
  
  for (auto i{a.begin()} ; i != a.end() ; i++ ) {
    cout << *i << ',';
  }

  cout << '\n';
  vector <int> b {1,2};
  b.insert(b.end(),a.begin(),a.end());
  for (auto i{b.begin()} ; i != b.end() ; i++ ) {
    cout << *i << ',';
  }

  return 0;
}
