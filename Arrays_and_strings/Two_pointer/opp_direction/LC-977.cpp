// 977. Squares of a Sorted Array

// Given an integer array nums sorted in non-decreasing order,
// return an array of the squares of each number,
// also sorted in non-decreasing order.
//
// Example 1:
//
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
//
// Explanation:
// After squaring:
// [16,1,0,9,100]
//
// After sorting:
// [0,1,9,16,100]
//
// Example 2:
//
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
//
// Constraints:
//
// 1 <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4
// nums is sorted in non-decreasing order.
//
// Follow-up:
// Can you solve it in O(n) time without sorting the result?
//
// code:

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        // Left pointer starts at the beginning
        int left = 0;

        // Right pointer starts at the end
        int right = nums.size() - 1;

        // Stores the squared values
        vector<int> ans;

        // The largest absolute value will always be
        // either at the left or right end
        while (left <= right) {

            // If the left value has a larger absolute value,
            // its square will be larger
            if (abs(nums[left]) > abs(nums[right])) {

                // Add the larger square
                ans.push_back(nums[left] * nums[left]);

                // Move left pointer
                left++;
            }
            else {

                // Right value has the larger or equal absolute value
                ans.push_back(nums[right] * nums[right]);

                // Move right pointer
                right--;
            }
        }

        // We added the largest squares first,
        // so reverse the array to get increasing order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {

    // Example input
    vector<int> nums = {-4, -1, 0, 3, 10};

    Solution obj;

    // Get the sorted squares
    vector<int> ans = obj.sortedSquares(nums);

    // Print the result
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}