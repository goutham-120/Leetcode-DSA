
// 974. Subarray Sums Divisible by K

// Given an integer array nums and an integer k, return the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [4,5,0,-2,-3,1], k = 5
// Output: 7
// Explanation: There are 7 subarrays with a sum divisible by k = 5:
// [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
// Example 2:

// Input: nums = [5], k = 9
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // Store: remainder -> number of times this remainder
        // has appeared in previous prefix sums
        unordered_map<int, int> mp;

        // Before the array starts, prefix sum is 0
        // and its remainder is also 0.
        // This helps count subarrays starting from index 0.
        mp[0] = 1;

        int currsum = 0;  // Current prefix sum
        int t = 0;        // Number of valid subarrays

        for (int i = 0; i < nums.size(); i++) {

            // Calculate the current prefix sum
            currsum += nums[i];

            // Get the remainder of the current prefix sum
            // when divided by k.
            //
            // The extra operations handle negative prefix sums
            // and ensure the remainder is always non-negative.
            int mod = ((currsum % k) + k) % k;

            // If the same remainder appeared before,
            // the difference between the two prefix sums
            // will be divisible by k.
            //
            // That difference represents the sum of a subarray.
            if (mp.count(mod)) {
                t += mp[mod];
            }

            // Store this remainder for future prefix sums
            mp[mod]++;
        }

        return t;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = solution.subarraysDivByK(nums, k);

    // Print the result
    cout << "Number of subarrays with sum divisible by " << k << ": " << result << endl;

    return 0;
}
