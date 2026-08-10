// 189. Rotate Array

 

// Example 1:

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]
// Example 2:

// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]
 

// Constraints:

// 1 <= nums.length <= 105
// -231 <= nums[i] <= 231 - 1
// 0 <= k <= 105
 

// Follow up:

// Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();

        // If k is greater than n, rotating k times is
        // equivalent to rotating k % n times.
        k %= n;

        // Step 1: Reverse the entire array.
        // This brings the last k elements to the front,
        // but they are currently in reverse order.
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements.
        // This puts the last k elements back into
        // their original order.
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements.
        // This restores the original order of the remaining
        // elements.
        reverse(nums.begin() + k, nums.end());
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    solution.rotate(nums, k);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}