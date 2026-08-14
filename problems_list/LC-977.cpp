// 977. Squares of a Sorted Array
//
// Given an integer array nums sorted in non-decreasing order, return an array
// of the squares of each number, also sorted in non-decreasing order.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> ans;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans.push_back(nums[left] * nums[left]);
                left++;
            } else {
                ans.push_back(nums[right] * nums[right]);
                right--;
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    Solution obj;
    vector<int> ans = obj.sortedSquares(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
