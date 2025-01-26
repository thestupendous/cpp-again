#include <cstdint>
#include<iostream>
#include<string>
/*
 *
 *
*/
using std::cout,std::string;

class Item {
  private:
    uint32_t size;
    string name;
  public:
    void setItem(uint32_t s,const string& n){
      size = s;
      name = n;
    }
    
    const string& getItemName()  {
      return name;
    }

    void printItem(){
      cout << "printing : ";
      cout << name << ',';
      cout << &name << '\n';
    }
};

int main() {
  Item asksy;
  asksy.setItem(30,"joe");
  cout<<"asksy\n";
  asksy.printItem();

  string a2Name;
  a2Name = asksy.getItemName();
  cout << "copied var : ";
  cout << a2Name << ',';
  cout << &a2Name << '\n';
  a2Name[1] = 'e';
  cout << "changed var : ";
  cout << a2Name << ',';
  cout << &a2Name << '\n';
  asksy.printItem();

  return 0;
}
