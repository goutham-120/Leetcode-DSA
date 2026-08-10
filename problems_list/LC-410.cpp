// 410. Split Array Largest Sum

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

 

// Example 1:

// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
// Example 2:

// Input: nums = [1,2,3,4,5], k = 2
// Output: 9
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
 

// Constraints:

// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 106
// 1 <= k <= min(50, nums.length)

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isvalid(vector<int> nums, int k, int mid) {
        // Start with one subarray since at least one partition always exists.
        int tot = 1, sum = 0;

        for (int i = 0; i < nums.size(); i++) {

            // Keep extending the current subarray as long as its sum
            // does not exceed the allowed maximum (mid).
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                // Once adding the current element crosses the limit,
                // we are forced to begin a new subarray because
                // subarrays must remain contiguous.
                tot++;
                sum = nums[i];
            }
        }

        // If we can partition using at most k subarrays,
        // then this maximum sum (mid) is achievable.
        return tot <= k;
    }

    int splitArray(vector<int>& nums, int k) {
// The minimum possible answer is the largest element because
// every element must belong to exactly one subarray. Since no
// subarray can split an element, the largest element itself
// must fit inside some subarray. Therefore, the largest subarray
// sum can never be smaller than max(nums).

// The maximum possible answer is the sum of the entire array because
// putting all elements into a single subarray is always a valid partition
// (or we can always choose not to split further). Hence, the largest
// subarray sum can never exceed the total sum of the array.
int l = 0, r = 0, ans = -1;
        l = *max_element(nums.begin(), nums.end());
        for (int i : nums) {
            r += i;
        }
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isvalid(nums, k, mid)) {

                // Since mid is feasible, try to minimize the answer further.
                ans = mid;
                r = mid - 1;
            }
            else {

                // Current limit is too small, so increase the allowed maximum.
                l = mid + 1;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;

    cout << "the minimized largest sum of the split is "
         << sol.splitArray(nums, k) << endl;

    return 0;
}