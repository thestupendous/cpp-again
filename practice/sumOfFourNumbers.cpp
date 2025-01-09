// sum of four integers

#include <iostream>

void readNum(int& num){
    std::cin>>num;
}

constexpr int calculateSum(int num1,int num2,int num3,int num4){
    return num1+num2+num3+num4;
}

int main(){
    int num1,num2,num3,num4;
    readNum(num1);
    readNum(num1);
    readNum(num1);
    readNum(num1);

    int sum = calculateSum(num1,num2,num3,num4);
}