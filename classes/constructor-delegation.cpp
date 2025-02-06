#include <iostream>

class Box {
private:
    double length;
    double width;
    double height;

public:
    // Constructor with all parameters
    Box(double l, double w, double h) : length(l), width(w), height(h) {
        std::cout << "Constructor with three parameters called." << std::endl;
    }

    // Constructor delegating to the three-parameter constructor
    Box(double size) : Box(size, size, size) {
        std::cout << "Constructor with one parameter called." << std::endl;
    }

    // Default constructor delegating to the one-parameter constructor
    Box() : Box(1.0) {
        std::cout << "Default constructor called." << std::endl;
    }

    void printDimensions() {
        std::cout << "Length: " << length << ", Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    Box defaultBox; // This will call the default constructor
    defaultBox.printDimensions();

    Box cube(5.0); // This will call the one-parameter constructor, which delegates to three-parameter
    cube.printDimensions();

    Box customBox(2.0, 3.0, 4.0); // This directly calls the three-parameter constructor
    customBox.printDimensions();

    return 0;
}
