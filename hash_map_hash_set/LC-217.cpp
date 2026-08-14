// 217. Contains Duplicate

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

// Example 1:

// Input: nums = [1,2,3,1]

// Output: true

// Explanation:

// The element 1 occurs at the indices 0 and 3.

// Example 2:

// Input: nums = [1,2,3,4]

// Output: false

// Explanation:

// All elements are distinct.

// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]

// Output: true

 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109

//code:
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Store numbers that we have already seen
        unordered_set<int> rep;

        // Traverse through every number
        for (int num : nums) {

            // If the number is already present,
            // we found a duplicate
            if (rep.count(num)) {
                return true;
            }

            // Store the current number
            rep.insert(num);
        }

        // No duplicate was found
        return false;
    }
};

int main() {

    // Example input
    vector<int> nums = {1, 2, 3, 1};

    Solution obj;

    // Call the function and print the result
    cout << boolalpha << obj.containsDuplicate(nums);

    return 0;
}