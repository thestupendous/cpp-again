//print elements of an array using recursion

#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define ui unsigned int

void print_recursively(string * names, ui index) {
    cout<< names[index];

    if (index-1 < 0 )
        return;
    print_recursively(names,index-1);

}


int main(){

    string names[] = { "x", "y", "z", "k", "b" };
    ui sizeofStrArray = 5;
    ui index = sizeofStrArray - 1;

    print_recursively(names,index);


    return 0;
}