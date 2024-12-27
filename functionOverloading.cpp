#include "standardHeader.h"

/// @brief 
/// @param x 
/// @param y 
/// @return 
int add (int x, int y) {
    return (x+y);
}

/// @brief 
/// @param x 
/// @param y 
/// @return 
double add (double x, double y) {
    return (x+y);
}

/// @brief 
/// @param x 
/// @param y 
/// @param z 
/// @return 
int add (int x, int y, int z) {
    return (x+y+z);
}

void print(int x)
{
    cout << "int " << x << '\n';
}

void print(double d)
{
    cout << "double "<< d << '\n';
}


int main(){
    cout << add(1, 2); // calls add(int, int)
    cout << '\n';
    cout << add(1.2, 3.4) << '\n'; // calls add(double, double)
    cout << add(20, 5, 100) << '\n'; // calls add(double, double)

    print('a'); // char does not match int or double, so what happens?
    //print(5L); // long does not match int or double, so what happens?


    return 0;
}
