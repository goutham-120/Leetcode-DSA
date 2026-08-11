// 560. Subarray Sum Equals K

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

 

// Example 1:

// Input: nums = [1,1,1], k = 2
// Output: 2
// Example 2:

// Input: nums = [1,2,3], k = 3
// Output: 2
 

// Constraints:

// 1 <= nums.length <= 2 * 104
// -1000 <= nums[i] <= 1000
// -107 <= k <= 107

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        // Store: prefix sum -> how many times this prefix sum has occurred
        unordered_map<int, int> mp;

        // A prefix sum of 0 exists once before the array starts.
        // This helps us count subarrays that start from index 0.
        mp[0] = 1;

        int currsum = 0;  // Current prefix sum
        int t = 0;        // Number of subarrays whose sum is k

        for (int i = 0; i < nums.size(); i++) {

            // Calculate prefix sum up to the current index
            currsum += nums[i];

            // If:
            // current prefix sum - previous prefix sum = k
            //
            // Then:
            // previous prefix sum = current prefix sum - k
            //
            // So we check whether (currsum - k) has appeared before.
            if (mp.count(currsum - k)) {

                // If it appeared multiple times, each occurrence
                // gives us a different subarray with sum k.
                t += mp[currsum - k];
            }

            // Store the current prefix sum for future subarrays
            mp[currsum]++;
        }

        return t;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = solution.subarraySum(nums, k);

    // Print the result
    cout << "Total number of subarrays whose sum equals to " << k << " is: " << result << endl;

    return 0;
}
