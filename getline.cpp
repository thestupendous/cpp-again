#include <iostream>
#include <string>

using std::getline, std::cout, std::cin, std::getline, std::string;

int main() {
  string v{}, line{};
  while (!cin.eof()) {
    getline(cin, line);

    if (cin.fail()) {
      // error
      break;
    }

      cout << "\tYe line : [" << line << "]\n";
    line += '\n';
    v += line ;

  }

  cout << "[" << v << "]\n";
  return 0;
}
