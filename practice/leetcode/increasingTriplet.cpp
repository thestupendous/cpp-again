// https://leetcode.com/problems/increasing-triplet-subsequence
// dekha hua soln from site algo.monster

#include "..\..\standardHeader.h"
#include <vector>
// #include<limits>

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int num;
        bool found = false;

        int min(INT_MAX), mid(INT_MAX);
        for (int i(0); i < nums.size(); i++)
        {
            num = nums[i];
            if (num > mid)
            {
                found = true;
                break;
            }
            if (num <= min)
            {
                min = num;
                // mid=INT_MAX;
            }
            else if (num < mid)
            {
                mid = num;
            }
        }

        if (found)
        {
            // if (min!=INT_MAX && mid!=INT_MAX){
            return true;
            //}
        }
        return false;
    }
};

int main()
{
    vector<int> arr({20, 100, 10, 12, 5, 13});

    for (auto v : arr)
    {
        cout << v << ",";
    }
    cout << endl;

    Solution solve;
    cout << solve.increasingTriplet(arr);

    return 0;
}
/*
    A quick brown fox jumps over the lazy dog.
    THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.
      3.13.1
*/