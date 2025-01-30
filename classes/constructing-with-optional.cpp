/*
 * making friend function to call constructor
 * so that constructor can stay private 
*/

#include <cmath>
#include <iostream>
#include <optional>
#include <random>
using std::cout;

class Fraction {
public:
  friend std::optional<Fraction> createFraction(int num, int den);

private:
  int numerator{0};
  int denominator{1};

    Fraction(int num,int den)
      : numerator(num), denominator(den)
    {
    }
};

std::optional<Fraction> createFraction(int num, int den) {
  if (den== 0)
    return {};
  return Fraction{ num, den };
}

int main() {
  auto f1 { createFraction(0,1) };
  if (f1.has_value()){
    cout << "Fraction created\n";
  }

  auto f2 { createFraction(0,0) };
  if (f2.has_value()){
    cout << "Fraction created\n";
  }else {
    cout << "Bad Fraction\n";
  }
  
  return 0;
}
