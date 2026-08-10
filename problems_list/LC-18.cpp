// 18. 4Sum

// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;

        // Sort the array so that we can use two pointers
        // and easily handle duplicate values.
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Fix the first element.
        for (int i = 0; i < n; i++) {

            // Skip duplicate values for i.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Fix the second element.
            for (int j = i + 1; j < n; j++) {

                // Skip duplicate values for j.
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                // Use two pointers to find the remaining
                // two elements whose sum completes the target.
                int l = j + 1;
                int r = n - 1;

                while (l < r) {

                    // Use long long to prevent integer overflow.
                    long long total = (long long)nums[i]
                                    + nums[j]
                                    + nums[l]
                                    + nums[r];

                    if (total == target) {

                        // Found a valid quadruplet.
                        ans.push_back({
                            nums[i], nums[j], nums[l], nums[r]
                        });

                        l++;
                        r--;

                        // Skip duplicate values for l.
                        while (l < r && nums[l] == nums[l - 1])
                            l++;

                        // Skip duplicate values for r.
                        while (l < r && nums[r] == nums[r + 1])
                            r--;
                    }
                    else if (total > target) {

                        // Decrease r to reduce the sum.
                        r--;
                    }
                    else {

                        // Increase l to increase the sum.
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};