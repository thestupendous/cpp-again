/*
  IntPair p { 1, 2 }; // create named object p initialized with { 1, 2 }
  IntPair { 1, 2 };   // create temporary object initialized with { 1, 2 }
  { 1, 2 };           // compiler will try to convert { 1, 2 } to temporary 
      object matching expected type (typically a parameter or return type)
*/
#include <iostream>
using std::cout;

class IntPair {
public:
  IntPair(int a, int b) : x{a}, y{b} {}
  int gx() const { return x; }
  int gy() const { return y; }

private:
  int x;
  int y;
};

void print(IntPair p) { cout << "(" << p.gx() << ", " << p.gy() << ")\n"; }

int main() {
  // Case 1: Pass variable
  IntPair p{3, 4};
  print(p);

  // Case 2: Construct temporary IntPair and pass to function
  print(IntPair{1, 2});

  // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to
  // function
  print({7, 8});

  return 0;
}
