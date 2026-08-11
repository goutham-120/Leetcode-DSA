// 238. Product of Array Except Self

// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

// You must write an algorithm that runs in O(n) time and without using the division operation.

 

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]
 

// Constraints:

// 2 <= nums.length <= 105
// -30 <= nums[i] <= 30
// The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.

//code:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1); //ans will store the product of array except self
        for(int i=1;i<n;i++){
            ans[i]=ans[i-1]*nums[i-1]; //ans[i] will store the product of all elements to the left of i
        }
        int suff=nums[n-1]; //suff will store the suffix product of the array
        for(int i=n-2;i>=0;i--){
            ans[i]=ans[i]*suff; //ans[i] will be multiplied with the suffix product to get the final answer
            suff*=nums[i]; //suff will be updated to the next suffix product
        }
       
        return ans;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,2,3,4};
    vector<int> ans=sol.productExceptSelf(nums);
    cout<<"the product of array except self is: ";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}