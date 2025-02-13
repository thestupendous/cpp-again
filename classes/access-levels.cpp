#include <iostream>
/*
        One nuance of C++ access levels that is often missed or misunderstood
        is that access to members is defined on a per-class basis,
        not on a per-object basis.

        One object's member function can access private data members of
        another object of the same class!
*/
class Kid {
private:
  std::string name;

public:
  void playsWith(const Kid &p2) const {
    std::cout << name << " plays with " << p2.name << '\n';
  }

  void setName(std::string_view names) { name = names; }
};

int main() {
  Kid cof;
  cof.setName("Cof");
  Kid jog;
  jog.setName("Jog");

  cof.playsWith(jog);

  return 0;
}
