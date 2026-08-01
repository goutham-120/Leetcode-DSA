// 540. Single Element in a Sorted Array
]
// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.

 

// Example 1:

// Input: nums = [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: nums = [3,3,7,7,10,11,11]
// Output: 10
 

// Constraints:

// 1 <= nums.length <= 105
// 0 <= nums[i] <= 105

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,n=nums.size();
        if(nums.size()==1) return nums[0]; //
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid==0&&nums[0]!=nums[1]) return nums[mid]; //if mid is 0 and nums[0] is not equal to nums[1], return nums[0] because it must be the single element
            if(mid==n-1&&nums[n-1]!=nums[n-2]) return nums[mid];//if mid is n-1 and nums[n-1] is not equal to nums[n-2], return nums[n-1] because it must be the single element
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]) return nums[mid];//if nums[mid] is not equal to nums[mid-1] and nums[mid+1], return nums[mid] because it must be the single element
            if(mid%2==0){ //if mid is even, left and right array sizes must be even
                if(nums[mid]==nums[mid-1]) r=mid-1;//if nums[mid] is equal to nums[mid-1], it means (as mid,mid-1 make a pair) the left half before mid-1 has odd length ,meaning one element in that cant make a pair ,its the single element so we move left to find the single element
                else l=mid+1;//if nums[mid] is not equal to nums[mid-1], it means the left half before mid has even length ,meaning all elements in that can make a pair ,so we move right to find the single element
            }
            else{//if mid is odd, left and right array sizes must be odd
                if(nums[mid]==nums[mid-1]) l=mid+1;//if nums[mid] is equal to nums[mid-1], it means (as mid,mid-1 make a pair) the left half before mid-1 has even length ,meaning all elements in that can make a pair ,so we move right to find the single element
                else r=mid-1;//if nums[mid] is not equal to nums[mid-1], it means  the left half before mid has odd length ,meaning one element in that cant make a pair ,its the single element so we move left to find the single element
            }
        }
        return 0;
    }
};
int main(){
    Solution sol;
    vector<int> nums={1,1,2,3,3,4,4,8,8};
    cout<<"the single element in the sorted array is "<<sol.singleNonDuplicate(nums)<<endl;
    return 0;
}