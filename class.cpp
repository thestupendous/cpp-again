#include <iostream>
#include <string>
using namespace std;
#define ui unsigned int

class Cust {
  ui id;
  string name;

public:
  ui age;
  void printHello();
};

void Cust::printHello() { cout << "Hii customers\n"; }

class CustInfo : public Cust {};

int main() {

  CustInfo c;
  // accessing public members of super class through derived class
  c.age = 20;
  c.printHello();

  int x{3};
  cout << "x " << x << endl;
  return 0;
}
