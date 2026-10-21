// ============================================================
// Title: 746. Min Cost Climbing Stairs
// ============================================================

// Problem Statement:
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
// Once you pay the cost, you can either climb one or two steps.
//
// You can either start from the step with index 0, or the step with index 1.
//
// Return the minimum cost to reach the top of the staircase, which is the position
// just past the last step (index cost.length).

// ============================================================
// Example 1:
// ============================================================
//
// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// ============================================================
// Example 2:
// ============================================================
//
// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

// ============================================================
// Constraints:
// ============================================================
//
// - 2 <= cost.length <= 1000
// - 0 <= cost[i] <= 999

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
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        // dp[i] stores the minimum cost to reach and pay for step i
        vector<int> dp(n, 0);

        // Base cases: we can start from step 0 or step 1
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the DP table
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // To reach the top (past the last step), we can arrive
        // from either step n - 1 or step n - 2
        return min(dp[n - 1], dp[n - 2]);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Example 1 Output: " << sol.minCostClimbingStairs(cost1) << " (Expected: 15)" << endl;

    // Example 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Example 2 Output: " << sol.minCostClimbingStairs(cost2) << " (Expected: 6)" << endl;

    return 0;
}
