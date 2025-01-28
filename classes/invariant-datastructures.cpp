/*
 * program to show invariant datastructure using struct can't 
 * be implemented easily.
 *
 * */
#include <iostream>
#include <string>
using std::string, std::cout;

struct Employee {
  std::string name{"Akash"};
  char firstInitial{'A'};

  void print() const {
    cout << "employee " << name << " has initial " << firstInitial << '\n';
  }
};

int main() {
  Employee e1;
  e1.print();
  e1.name = "Vishwroop";
  e1.print();

  return 0;
}
