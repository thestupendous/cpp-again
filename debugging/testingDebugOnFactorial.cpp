//factorial using recursion

#include<iostream>
using namespace std;

using ui = unsigned;
ui res = 1;

ui findFactorial(ui n){

    if (n==1) return 1;
    res = n * findFactorial(n-1) ;
    return res;

}


int main(){

    ui num;
    cin>>num;

    const ui resultFactorial = findFactorial(num);

    cout<<"factorial of "<<num<<" is : "<<resultFactorial<<'\n';

    return 0;
}