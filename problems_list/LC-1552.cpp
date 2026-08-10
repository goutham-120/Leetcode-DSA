// 1552. Magnetic Force Between Two Balls

// In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

// Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

// Given the integer array position and the integer m. Return the required force.

 

// Example 1:


// Input: position = [1,2,3,4,7], m = 3
// Output: 3
// Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is 3. We cannot achieve a larger minimum magnetic force than 3.
// Example 2:

// Input: position = [5,4,3,2,1,1000000000], m = 2
// Output: 999999999
// Explanation: We can use baskets 1 and 1000000000.
 

// Constraints:

// n == position.length
// 2 <= n <= 105
// 1 <= position[i] <= 109
// All integers in position are distinct.
// 2 <= m <= position.length

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool ispossible(vector<int>& nums, int m, int minallowed) {

        // Place the first ball at the leftmost position since doing so
        // leaves the maximum possible space for placing the remaining balls.
        int tot = 1, lastpos = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Greedily place the next ball at the earliest position that
            // still maintains the required minimum distance. Placing it any
            // later would only reduce the space available for future balls.
            if (nums[i] - lastpos >= minallowed) {
                tot++;
                lastpos = nums[i];
            }

            // Once all m balls are placed, this minimum distance is achievable.
            if (tot == m) return true;
        }

        // Couldn't place all m balls while maintaining the required distance.
        return false;
    }

    int maxDistance(vector<int>& position, int m) {

        sort(position.begin(), position.end());
        int n = position.size();

        // Search space:
        // - Minimum = 1, since positions are distinct and the smallest possible
        //   positive minimum distance between any two placed balls is 1.
        // - Maximum = distance between the leftmost and rightmost positions,
        //   because no two balls can be farther apart than the entire range.
        int l = 1, r = position[n - 1] - position[0];

        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (ispossible(position, m, mid)) {

                // If we can maintain this minimum distance, try to increase it
                // and look for an even better answer.
                ans = mid;
                l = mid + 1;
            }
            else {

                // Current minimum distance is too large to place all m balls,
                // so we must reduce our expectation.
                r = mid - 1;
            }
        }

        return ans;
    }
};