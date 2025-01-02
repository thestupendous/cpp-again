//https://leetcode.com/problems/product-of-array-except-self
#include "..\..\standardHeader.h"
#include<vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int prod2 = 1;
        unsigned zi = INT_MAX;
        for (int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if (zi!=INT_MAX) {
                    prod2=0;
                    prod=0;
                    break;
                }
                zi = i;
                prod=0;
                continue;
            }
            prod2 *= nums[i];
            prod *=nums[i];
        }
        vector<int> result(nums.size(),prod);

        for(int i(0);i<nums.size();i++){
            if(nums[i]==0) result[i]=prod2;
            else
                result[i] /= nums[i];
        }
        return result;
    }
};

int main(){
    Solution solve;

    vector<int> vec({1,2,3,4});
    vector<int> ans(solve.productExceptSelf(vec));
    for(auto num: ans){
        cout<<num<<',';
    }cout<<endl;
}