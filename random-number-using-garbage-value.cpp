#include <iostream>
using std::cout;

int getRandom(int LowerLimit, int UpperLimit) {
  int *p = new int;
  int val = *p;
  cout << "val is " << val << '\n';
  if (val < 0) val=-val;
  delete p;
  return ( ( val % (UpperLimit - LowerLimit) ) + LowerLimit );
}

int main() {
  int num1 = getRandom(0, 50);
  int num2 = getRandom(0, 50);
  int num3 = getRandom(0, 50);
  int num4 = getRandom(0, 50);
  int num5 = getRandom(0, 50);

  cout << num1 << '\n';
  cout << num2 << '\n';
  cout << num3 << '\n';
  cout << num4 << '\n';
  cout << num5 << '\n';

  cout << __TIME__ << '\n';
  return 0;
}
