// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

 

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]
 

// Constraints:

// 1 <= nums.length <= 104
// -231 <= nums[i] <= 231 - 1

//hint: if we want all zeroes at end then we can bring all non-zero elements to the front.
//code:
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),l=0; //l is the left pointer which will point to the index where we want to place the next non-zero element
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[l]); //we swap the current non-zero element with the element at index l and then increment l to point to the next index where we want to place the next non-zero element
                l++;
            }
            //in this way all non-zero elements will be moved to the front of the array and all zeroes will be moved to the end of the array while maintaining the relative order of the non-zero elements
        }
        
    }
};
int main(){
    Solution sol;
    vector<int> nums={0,1,0,3,12};
    sol.moveZeroes(nums);
    cout<<"the array after moving all zeroes to the end is: ";
    for(int i=0;i<nums.size();i++)
        cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}
