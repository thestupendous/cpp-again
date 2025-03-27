/*
  hackerrank - Project Euler #1: Multiples of 3 and 5
  https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem?isFullScreen=true

2
10
100


*/

#include <iostream>
#include <cstdint>
using namespace std;


int main(){
    uint_fast32_t t;
    cin >> t;
    for(uint_fast32_t a0 = 0; a0 < t; a0++){
        uint_fast32_t n;
        cin >> n;
        n--;
        
        
        uint_fast64_t sum3 {0};
        uint_fast64_t sum5 {0};
        uint_fast64_t sum15 {0};
        uint_fast32_t mul3 { n - n%3 };
        uint_fast32_t mul5 { n - n%5 };
        uint_fast32_t mul15 { n - n%15 };
        
        //TODO low case
        
        uint_fast64_t p3 = ( mul3 * mul3  + 3 * mul3 ) ;
        uint_fast64_t p5 = ( mul5 * mul5  + 5 * mul5 ) ;
        uint_fast64_t p15 = ( mul15 * mul15  + 15 * mul15 ) ;
        if (p3%6 != 0 ) cout << "not by 3!\n";
        if (p5%10 != 0 ) cout << "not by 5!\n";
        sum3 = p3 / 6;
        sum5 = p5 / 10;
        sum15 = p15 / 30;
        cout << "3 " << sum3 << '\n';
        cout << "5 " << sum5 << '\n';
        cout << "15 " << sum15 << '\n';
        
    
        
        cout << sum3 + sum5 - sum15 << '\n';
    }
    return 0;
}