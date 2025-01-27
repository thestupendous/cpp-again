#include <iostream>
using std::cout;

class A {
  int x;
  ~A() { cout << "destroyed " << x << '\n'; }
};

int &getLocalReference(int osdf) {
  int localVar = 10;
  return localVar; // Dangling reference
}

int main() {
  int *a = new int;
  *a = 10;
  int *b = a;

  cout << *a << '\n';
  cout << *b << '\n';
  // cout << c << '\n';

  // c = 20;
  // cout << a << '\n';
  // cout << *b << '\n';
  // cout << c << '\n';

  delete b;
  cout << *a << '\n';
  cout << *b << '\n';
  // cout << c << '\n';

  // ye pakka dangling reference degi
  int &ref = getLocalReference(234); // ref is now a dangling reference
  cout << " ref " << ref << '\n';
  return 0;
}










