#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::string, std::string_view;

class Ball {
public:
  Ball(string_view col = "Black", double rad = 10.0) : color{col}, radius{rad} { print(); }
  Ball(double rad)
      : Ball{ "Black", rad }
  {
    print();
  }
  void print() const { cout << "Ball(" << color << ", " << radius << ")\n"; }

private:
  string color{"Black"};
  double radius{10};
};

int main() {
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}
