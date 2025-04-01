/*
    Given an integer n, we need to repeatedly find the sum of its digits until the result becomes a single-digit number.
    link - https://www.geeksforgeeks.org/finding-sum-of-digits-of-a-number-until-sum-becomes-single-digit/
*/

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

int digitSum(int n) {
    
    // int result = 11;
    int result=n;
    while (result>=10) {
        //int k = result;
        int k=result;
        result=0;
        cout << "This n,k,result : " << n << ',' << k << ',' << result << '\n';
        while(k){
            result += k%10;
            k /= 10;
            cout << "now k " << k << '\n';
        }
        cout << "THIS n,k,result : " << n << ',' << k << ',' << result << '\n';
    }
    
    return result;
    
}

int main()
{

    
    cout << digitSum(5527) << '\n';
    return 0;
}