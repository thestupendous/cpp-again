#include <iostream>
using std::cout;

class Fraction {
public:
  Fraction(int num, int den)
      : numerator{num}, denominator{(den != 0) ? den : 1} {}

private:
  int numerator{};
  int denominator{1};
};

int main(){
  Fraction f{4,9};
  return 0;
}
