// program to show "Data hiding makes it possible to
// change implementation details without having to make changes in main"

#include <iostream>
struct Something {
  int value1{};
  int value2{};
  int value3{};
};

// what if you want to change it to ->
/*
  struct Something
  {
        int value[3] {}; // uses an array of 3 values
  };
  Now you will have to change implementation in main also

  To counter this, look at below class
*/

class SomethingClass {
  private:
    int m_value1 {};
    int m_value2 {};
    int m_value3 {};

public:
    void setValue1(int value) { m_value1 = value; }
    int getValue1() const { return m_value1; }
};

/*
 * This can be chaned easily
  class Something
  {
  private:
      int m_value[3]; // note: we changed the implementation of this class!

  public:
      // We have to update any member functions to reflect the 
      // new implementation
      void setValue1(int value) { m_value[0] = value; }
      int getValue1() const { return m_value[0]; }
};

*/

int main() {
  Something something;
  something.value1 = 5;
  std::cout << something.value1 << '\n';
}
