// 15. 3Sum

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.
 

// Constraints:

// 3 <= nums.length <= 3000
// -105 <= nums[i] <= 105

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Sort the array so we can use the two-pointer technique
        // and easily skip duplicate elements.
        sort(nums.begin(), nums.end());

        vector<vector<int>> v;

        int l = 0, n = nums.size(), num = 0, sum = 0;
        int r = 0;

        // Fix nums[i] as the first element of the triplet.
        // Then use two pointers to find the other two elements.
        for (int i = 0; i < n; i++) {

            // Skip duplicate values for i to avoid duplicate triplets.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // l starts just after i and r starts at the end.
            l = i + 1;
            r = n - 1;

            while (l < r) {

                // Calculate the sum of the three selected elements.
                sum = nums[l] + nums[r] + nums[i];

                if (sum == 0) {

                    // Found a valid triplet.
                    v.push_back({nums[i], nums[l], nums[r]});

                    // Skip duplicate values from the left pointer.
                    while (l < r && nums[l] == nums[l + 1])
                        l++;

                    // Skip duplicate values from the right pointer.
                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    // Move both pointers to search for the next triplet.
                    l++;
                    r--;
                }
                else if (sum < 0) {

                    // Since the array is sorted, increase l
                    // to get a larger sum.
                    l++;
                }
                else if (sum > 0) {

                    // Decrease r to get a smaller sum.
                    r--;
                }
            }
        }

        return v;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = sol.threeSum(nums);

    cout << "The triplets that sum to zero are: " << endl;
    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}