#include <iostream>
#include <map>
#include <string>
#include <iterator>
using std::string,std::cout;


int main() {
  std::map <string,int> names;
  names["a"] = 34;
  names["o"] = 24;
  names["s"] = 30;
  names["["] = 3;
  names["k"] = 10;
  names["w"] = 301;
  names["q"] = 90;
  names["b"] = 11;
  names["Z"] = 4;

  for ( std::map<string,int>::iterator i {names.begin()} ; i != names.end() ; i++ ) {
    cout << i->first << ':' << i->second << '\n';
  }

  return 0;
}

