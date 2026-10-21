// ============================================================
// Title: 198. House Robber
// ============================================================

// Problem Statement:
// You are a professional robber planning to rob houses along a street.
// Each house has a certain amount of money stashed, the only constraint
// stopping you from robbing each of them is that adjacent houses have
// security systems connected and it will automatically contact the police
// if two adjacent houses were broken into on the same night.
//
// Given an integer array nums representing the amount of money of each
// house, return the maximum amount of money you can rob tonight without
// alerting the police.

// ============================================================
// Example 1:
// ============================================================
//
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// ============================================================
// Example 2:
// ============================================================
//
// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

// ============================================================
// Constraints:
// ============================================================
//
// - 1 <= nums.length <= 100
// - 0 <= nums[i] <= 400

// ============================================================
// Complexity:
// ============================================================
//
// Time Complexity:  O(n)
// Space Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // dp[i] stores the maximum money that can be robbed from houses 0 to i
        vector<int> dp(n, 0);

        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // For each house, we have two choices:
        // 1. Rob current house: add its money to dp[i - 2] (cannot rob adjacent house i - 1)
        // 2. Skip current house: take the maximum robbed up to previous house dp[i - 1]
        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 2, 3, 1};
    cout << "Example 1 Output: " << sol.rob(nums1) << " (Expected: 4)" << endl;

    // Example 2
    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << "Example 2 Output: " << sol.rob(nums2) << " (Expected: 12)" << endl;

    return 0;
}
