/*
 * Why it's is useful to have non member functions for doing some of class' work
 * which use public interface of class to access members
 */

#include <iostream>
#include <string>
#include <string_view>
using std::cout, std::string, std::string_view;

class Dahi {
private:
  string flavor = "vanilla";

public:
  const string &getFlavor() const { return flavor; }
  void setFlavor(string_view flavorI) { flavor = flavorI; }
};

void print(const Dahi &item) {
  cout << "ye hai dahi ka " << item.getFlavor() << " flavor\n";
}

int main() {
  Dahi item1;
  item1.setFlavor("Elaichi");
  print(item1);
  return 0;
}
