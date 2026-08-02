// 31. Next Permutation

// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.

// The replacement must be in place and use only constant extra memory.

// Example 1:

// Input: nums = [1,2,3]
// Output: [1,3,2]
// Example 2:

// Input: nums = [3,2,1]
// Output: [1,2,3]
// Example 3:

// Input: nums = [1,1,5]
// Output: [1,5,1]
 

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 100

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Start from the second last element because we'll compare each
        // element with the one immediately after it.
        int i = n - 2;

        // Find the first element (pivot) that is smaller than its next element.
        // Everything to the right of this pivot is in descending order,
        // meaning it is already the largest possible arrangement of that suffix.
        // To get the next permutation, this is the first position we must change.
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If no pivot is found, the array is completely descending,
        // which means it is already the last permutation.
        // Reversing the whole array later will produce the first permutation.
        if (i >= 0) {

            // Search from the end because the suffix is descending.
            // The first element greater than nums[i] encountered from the right
            // is automatically the smallest element greater than it,
            // giving the smallest possible increase.
            int j = n - 1;

            while (nums[j] <= nums[i]) {
                j--;
            }

            // Swap the pivot with its next larger element so that the number
            // becomes just larger than before, not unnecessarily larger.
            swap(nums[i], nums[j]);
        }

        // The suffix is still in descending order after the swap.
        // Reverse it to make it ascending, which is the smallest possible
        // arrangement of that suffix. This guarantees the immediate
        // next lexicographical permutation.
        reverse(nums.begin() + i + 1, nums.end());
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    solution.nextPermutation(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

//note: if a number is in decreasing order then no next permutation is possible that can be greater thanthe current number.