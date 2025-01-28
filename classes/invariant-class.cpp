#include <iostream>
#include <string>
using std::string, std::cout;

class Employee {
  string name{"Akash"};

public:
  void setName(std::string_view nameI) { name = nameI; }

  // using std::string::front() to get first letter
  char firstInitial() const { return name.front(); }

  void print() {
    cout << "Employee " << name << " hase initial letter " << firstInitial()
         << '\n';
  }
};

int main() {
  Employee e1;
  e1.setName("Vishwaroop");
  cout << e1.firstInitial();
  e1.print();

  //del 
  string del;
  cout << '[' << del.front() << "]\n";

  return 0;
}
