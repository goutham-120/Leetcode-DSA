// 88. Merge Sorted Array

// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

// Example 1:

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]
// Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
// The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
// Example 2:

// Input: nums1 = [1], m = 1, nums2 = [], n = 0
// Output: [1]
// Explanation: The arrays we are merging are [1] and [].
// The result of the merge is [1].
// Example 3:

// Input: nums1 = [0], m = 0, nums2 = [1], n = 1
// Output: [1]
// Explanation: The arrays we are merging are [] and [1].
// The result of the merge is [1].
// Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

// Constraints:

// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -109 <= nums1[i], nums2[j] <= 109

// code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,k=m+n-1,j=n-1; // i will point to the last element of nums1, j will point to the last element of nums2 and k will point to the last element of nums1 where we will place the largest element between nums1[i] and nums2[j]
        while(i>=0&&j>=0){
            if(nums1[i]>=nums2[j]){ // if nums1[i] is greater than or equal to nums2[j] then we will place nums1[i] at the end of nums1 and decrement both i and k so that we can place the next largest element at the end of nums1
                nums1[k]=nums1[i];
                k--;
                i--;
            }
            else{// if nums2[j] is greater than nums1[i] then we will place nums2[j] at the end of nums1 and decrement both j and k so that we can place the next largest element at the end of nums1
                nums1[k]=nums2[j];
               k--;
               j--;
            }
        }
        while(i>=0){ // if there are still elements in nums1 then we will place them at the end of nums1
            nums1[k--]=nums1[i--];
        }
        while(j>=0){// if there are still elements in nums2 then we will place them at the end of nums1
            nums1[k--]=nums2[j--];
        }
      
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    solution.merge(nums1, m, nums2, n);

    for (int num : nums1) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}