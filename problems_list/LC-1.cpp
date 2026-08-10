// 1. Two Sum
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// You are given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.
 

// Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?

//code:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store:
        // Key   -> element value
        // Value -> index of that element
        unordered_map<int, int> mp;

        // Traverse the array once
        for (int i = 0; i < nums.size(); i++) {

            // Find the value needed to make the target
            int complement = target - nums[i];

            // If the complement has already been seen,
            // we have found the required pair.
            if (mp.count(complement))
                return {mp[complement], i};

            // Store the current element and its index
            // for future complement lookups.
            mp[nums[i]] = i;
        }

        // No valid pair found (though the problem guarantees one exists)
        return {-1, -1};
    }
};
int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    
    cout << "Indices of the two numbers that add up to " << target << ": ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}