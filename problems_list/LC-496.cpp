// ============================================================
// Title: 496. Next Greater Element I
// ============================================================

// Problem Statement:
// The next greater element of some element x in an array is the
// first greater element that is to the right of x in the same array.
//
// You are given two distinct 0-indexed integer arrays nums1 and
// nums2, where nums1 is a subset of nums2.
//
// For each 0 <= i < nums1.length, find the index j such that
// nums1[i] == nums2[j] and determine the next greater element of
// nums2[j] in nums2. If it does not exist, the answer is -1.
//
// Return an array ans of length nums1.length such that
// ans[i] is the next greater element as described above.

// ============================================================
// Example 1:
// ============================================================
//
// Input:
// nums1 = [4,1,2]
// nums2 = [1,3,4,2]
//
// Output:
// [-1,3,-1]
//
// Explanation:
// The next greater element for 4 is -1.
// The next greater element for 1 is 3.
// The next greater element for 2 is -1.

// ============================================================
// Example 2:
// ============================================================
//
// Input:
// nums1 = [2,4]
// nums2 = [1,2,3,4]
//
// Output:
// [3,-1]

// ============================================================
// Constraints:
// ============================================================
//
// - 1 <= nums1.length <= nums2.length <= 1000
// - 0 <= nums1[i], nums2[i] <= 10^4
// - All integers in nums1 and nums2 are unique.
// - All the integers of nums1 also appear in nums2.

// ============================================================
// Complexity:
// ============================================================
//
// Time: O(n + m)
// Space: O(n)
//
// n = nums2.size()
// m = nums1.size()

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        // Map each number in nums2 to its next greater element.
        unordered_map<int, int> mp;

        int n = nums2.size();

        // Monotonic decreasing stack.
        // It stores elements that can potentially be the
        // next greater element for elements to their left.
        stack<int> st;

        // The last element has no element to its right,
        // so its next greater element is -1.
        st.push(nums2[n - 1]);
        mp[nums2[n - 1]] = -1;

        // Traverse nums2 from right to left.
        for (int i = n - 2; i >= 0; i--) {

            // Remove all elements that are smaller than or
            // equal to nums2[i]. They cannot be its NGE.
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If the stack is not empty, its top is the
            // nearest greater element.
            if (!st.empty()) {
                mp[nums2[i]] = st.top();
            }
            else {
                // No greater element exists to the right.
                mp[nums2[i]] = -1;
            }

            // Current element can be the NGE for future elements.
            st.push(nums2[i]);
        }

        // Replace every element in nums1 with its
        // precomputed next greater element.
        for (int& i : nums1) {
            i = mp[i];
        }

        return nums1;
    }
};

int main() {

    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    // Print the result.
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;

    return 0;
}
