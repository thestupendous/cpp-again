#include <iostream>
class Foo
{
private:
    int m_x {};
    int m_y {};

public:
    Foo(int x, int y)
      : m_x{x},m_y{y} // here's our constructor function that takes two initializers
       // members are initialized in the order they're defined 'in class'
    {
        std::cout << "Foo(" << x << ", " << y << ") constructed\n";
    }

    void print() const
    {
        std::cout << "Foo(" << m_x << ", " << m_y << ")\n";
    }
};

int main()
{
  //using direct list initializer
    Foo foo{ 6, 7 }; // calls Foo(int, int) constructor
    foo.print();

    Foo foo2( 10, 5 ); // calls Foo(int, int) constructor
    foo2.print();


    return 0;
}
