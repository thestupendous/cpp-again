#include <iostream>
using std::cout;

class Point3d {
private:
  int x;
  int y;
  int z;

public:
  void setValues(int xi, int yi, int zi) {
    x = xi;
    y = yi;
    z = zi;
  }
  void print() const { cout << '<' << x << ',' << y << ',' << z << ">\n"; }

  bool isEqualTo(const Point3d &point2) const {
    if (x == point2.x && y == point2.y)
      return true;
    return false;
  }
};

int main() {
  Point3d point1;
  point1.setValues(1, 2, 3);
  Point3d point2(point1);
  // point2.setValues(point1);

  point1.print();
  std::cout << '\n';
  std::cout << point2.isEqualTo(point1);
  return 0;
}
