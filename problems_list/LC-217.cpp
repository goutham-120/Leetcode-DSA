// 217. Contains Duplicate
//
// Given an integer array nums, return true if any value appears at least twice
// in the array, and return false if every element is distinct.

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution obj;

    cout << boolalpha << obj.containsDuplicate(nums);
    return 0;
}
