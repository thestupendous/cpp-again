/*
  hackerrank - Project Euler #2: Even Fibonacci numbers
  https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem?isFullScreen=true




*/

#include <iostream>
#include <cstdint>
using namespace std;


//int main(){
//    uint_fast32_t t;

map<long,long> list;

int main(){
    int t;
    cin >> t;
    long biggestKey {2};
    long chhotiBig {1};
    // init list for first 10
    list[1] = 0;
    list[2] = 2;
    list[3] = 2;
    list[4] = 2;
    list[5] = 2;
    list[6] = 2;
    list[7] = 2;
    list[8] = 10;
    list[9] = 10;
    list[10] = 10;

   
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        
        if(list.find(n) == list.end()) {
            // Find all fib <  n
            //      and     >= biggestKey

        }
    }
    return 0;
}
