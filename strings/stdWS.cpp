// std::ws stands for White Space

#include <iostream>
#include <string>

int main()
{
    //****important -> why cin>>ws is important with getline() */
    std::cout << "Pick 1 or 2: ";
    int choice{};
    std::cin >> choice;

    std::cout << "Now enter your name: ";
    std::string name2{};
    std::getline(std::cin >> std::ws, name2); // note: added std::ws here to avoid empty string in name2

    std::cout << "Hello, " << name2 << ", you picked " << choice << '\n';

    return 0;
}
