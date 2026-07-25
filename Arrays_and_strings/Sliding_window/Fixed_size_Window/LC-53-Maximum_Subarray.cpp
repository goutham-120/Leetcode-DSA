// 53. Maximum Subarray
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

//code:
#include <bits/stdc++.h>
#include <vector>
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxx=nums[0],curr=0;//maxx is the maximum sum of the subarray and curr is the current sum of the subarray
        for(int i:nums){
            curr+=i;
            maxx=max(curr,maxx); //we update the maximum sum of the subarray at each index
            if(curr<0){
                curr=0;  //
            }
        }
        return maxx;
    }
};
int main(){
    Solution sol;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<"the maximum subarray sum is: "<<sol.maxSubArray(nums)<<endl;
    return 0;
}