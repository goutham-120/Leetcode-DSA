// 1004. Max Consecutive Ones III

// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

// Example 1:

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
// Example 2:

// Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
// Output: 10
// Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
// 0 <= k <= nums.length

//code:
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroes=0; //count zeroes in the current window
        int l=0,r=0,maxlen=0; //l,r are the two pointers and maxlen is the maximum length of subarray with at most k zeroes
        for(r=0;r<nums.size();r++){
            if(nums[r]==0) zeroes++;
            while(zeroes>k){  //we can only replace at most k zeroes, so if the count of zeroes exceeds k, we need to shrink the window from left
                if(nums[l]==0) zeroes--;
                l++;
            }
             maxlen=max(maxlen,r-l+1); //this calculates the max length of window that contains only ones and also may be zeroes that were converted into ones.
        }
        return maxlen;
    }
};

int main(){
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=2;
    Solution s;
    cout<<"the maximum number of consecutive 1's in the array if you can flip at most k 0's is: "<<s.longestOnes(nums,k)<<endl;
    return 0;
}