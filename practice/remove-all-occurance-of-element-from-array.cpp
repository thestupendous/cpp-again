/*
 * Given an integer array arr[] and an integer ele the 
 * task is to the remove all occurrences of ele from arr[] 
 * in-place and return the number of elements which are 
 * not equal to ele. If there are k number of elements which 
 * are not equal to ele then the input array arr[] should 
 * be modified such that the first k elements should contain the 
 * elements which are not equal to ele and then the remaining 
 * elements. 
 * link - https://www.geeksforgeeks.org/remove-element/
*/

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

void removeElement(vector<int> &arr,int e) {
    unsigned int j{0}, count {0};
    for (unsigned int i{0};i<arr.size();i++) {
        if (arr[i] != e) {
            arr[j++] = arr[i];
        }
    }
    // new array elements count = j+1
}

int main()
{
    vector<int> arr {2,3,0,11,3,8,5,3,3,7,1,6,3,4}; 
    
    removeElement(arr,3);
    for(int num : arr) cout << num << ',';
    cout << '\n';
    return 0;
}
