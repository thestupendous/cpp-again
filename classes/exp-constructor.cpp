// Question from learncpp.com on constructors page
#include <cstdint>
#include <iostream>
#include <string>
using std::cout,std::string;

class Ball {
  public:
    Ball(string col, uint32_t rad)
      : color(col), radius(rad)
    {}
    void print() const {
      cout << "Ball(" << color << ", " << radius << ")\n";
    }
  private:
    string color {};
    uint32_t radius {};
};

int main() {
  Ball blue { "blue" , 10 };
  blue.print();

  Ball orange { "orange" , 15 };
  blue.print();
}
