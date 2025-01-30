#include<iostream>
class Foo // Foo is an aggregate
{
  public:
    int x {};
    int y {};
};

int main()
{
    Foo foo { 6, 7 }; // uses aggregate initialization
              std::cout << foo.x << ',' << foo.y << '\n';

    return 0;
}
