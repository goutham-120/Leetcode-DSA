/*
    Title: 739. Daily Temperatures

    Problem Statement:
    Given an array of daily temperatures, return an array where answer[i]
    is the number of days you have to wait after the ith day to get a warmer
    temperature. If there is no future day with a warmer temperature,
    answer[i] should be 0.

    Examples:
    Input:  temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

    Input:  temperatures = [30,40,50,60]
    Output: [1,1,1,0]

    Input:  temperatures = [30,60,90]
    Output: [1,1,0]

    Constraints:
    - 1 <= temperatures.length <= 10^5
    - 30 <= temperatures[i] <= 100

    Complexity:
    - Time: O(n)
    - Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        // Initially, assume there is no warmer day for every position.
        vector<int> ans(n, 0);

        // Store indices of temperatures.
        // The stack maintains a monotonic decreasing sequence of temperatures.
        stack<int> st;

        // Traverse from right to left because we are looking for a
        // warmer temperature somewhere to the right.
        for (int i = n - 1; i >= 0; i--) {

            // Remove all days whose temperatures are less than or equal
            // to the current temperature.
            // They can never be the next warmer day for index i.
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If the stack is not empty, its top is the nearest day
            // to the right having a strictly warmer temperature.
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Current index becomes a candidate for earlier days.
            st.push(i);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> ans = sol.dailyTemperatures(temperatures);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
