// 303. Range Sum Query - Immutable
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Given an integer array nums, handle multiple queries of the following type:

// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
 

// Constraints:

// 1 <= nums.length <= 104
// -105 <= nums[i] <= 105
// 0 <= left <= right < nums.length
// At most 104 calls will be made to sumRange.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class NumArray {
    vector<int> prefix;

public:
    NumArray(vector<int>& nums) {

        // Create prefix array of size n + 1
        // prefix[0] = 0
        prefix.resize(nums.size() + 1, 0);

        // Build the prefix sum array
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }

    int sumRange(int left, int right) {

        // Sum from left to right
        // = prefix[right + 1] - prefix[left]
        return prefix[right + 1] - prefix[left];
    }
};
int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    // Test sumRange
    cout << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}
