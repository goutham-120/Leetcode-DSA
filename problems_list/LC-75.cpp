// 75. Sort Colors

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

 

// Example 1:

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Example 2:

// Input: nums = [2,0,1]
// Output: [0,1,2]
 

// Constraints:

// n == nums.length
// 1 <= n <= 300
// nums[i] is either 0, 1, or 2.

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid=0; // l will make sure all 0's are on left, r will make sure all 2's are on right and mid will traverse the array by keeping all 1's in the middle
        while(mid<=r){
            if(nums[mid]==0){ // if mid is 0 then swap it with l and increment both l and mid so that we can keep all 0's on left and mid can traverse the array
                swap(nums[mid],nums[l]);
                l++;
                mid++;
            }
            else if(nums[mid]==2){ // if mid is 2 then swap it with r and decrement r so that we can keep all 2's on right and mid can traverse the array
                 swap(nums[mid],nums[r]);
                    r--;
            }
            else{ // if mid is 1 then just increment mid so that we can keep all 1's in the middle and mid can traverse the array
                mid++;
            }
        }
        
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    solution.sortColors(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}