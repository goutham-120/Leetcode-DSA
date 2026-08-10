// 349. Intersection of Two Arrays

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        // Store all unique elements of nums1.
        unordered_set<int> st(nums1.begin(), nums1.end());

        // Store the final unique intersection.
        unordered_set<int> result;

        // Check every element of nums2.
        for (int x : nums2) {

            // If x exists in nums1, it is part of the intersection.
            if (st.count(x)) {
                result.insert(x);
            }
        }

        // Convert the set to a vector.
        return vector<int>(result.begin(), result.end());
    }
};
int main() {
    Solution solution;
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};
    vector<int> result = solution.intersection(nums1, nums2);

    cout << "The intersection of the two arrays is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}