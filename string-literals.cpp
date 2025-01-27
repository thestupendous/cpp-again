#include<iostream>
#include<string>
using std::string,std::cout;
using namespace std::string_literals;
int main(){
  std::string a = "Th eral with \backslashes  uotes\".)"s;
  std::string b = R"(This is a "raw" string l
  iteral with \backslashes\ and "q
  uotes".)"s;
  std::cout << a << '\n';
  std::cout << b << '\n';
  return 0;
}
