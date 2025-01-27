#include <iostream>
#include <string>
#include <string_view>
using std::cout,std::string;

class Employee {
  std::string name;

public:
  void setName(std::string_view nameI) { name = nameI; }
  const std::string &getName() const { return name; }
 ~Employee();
};
Employee::~Employee(){
  cout << "DESTROYED " << name << "\n";
}

Employee createEmployee(std::string_view nameI)
{
  Employee a;
  a.setName(nameI);
  return a;
}

int main(){

  cout << createEmployee("one"s).getName() << '\n';

  const std::string& ref { createEmployee("two"s).getName() };
  cout << ref << '\n';

  std::string val {createEmployee("three"s).getName()} ;
  cout << val <<'\n';

  int k=93;
  cout << val << k <<'\n';
  

  return 0;
}

