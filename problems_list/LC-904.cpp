// 904. Fruit Into Baskets

// You are visiting a row of trees. Each tree has a type of fruit,
// represented by an integer in the fruits array.
//
// You have two baskets, and each basket can hold only one type of fruit.
// There is no limit on the number of fruits of that type.
//
// Starting from any tree, you must pick exactly one fruit from every
// tree while moving to the right.
// You must stop when you reach a tree whose fruit type cannot fit
// into either basket.
//
// Return the maximum number of fruits you can collect.
//
// Example 1:
//
// Input: fruits = [1,2,1]
// Output: 3
//
// Explanation:
// You can collect all 3 fruits because there are only 2 types.
//
// Example 2:
//
// Input: fruits = [0,1,2,2]
// Output: 3
//
// Explanation:
// You can collect [1,2,2].
//
// Example 3:
//
// Input: fruits = [1,2,3,2,2]
// Output: 4
//
// Explanation:
// You can collect [2,3,2,2].
//
// Constraints:
//
// 1 <= fruits.length <= 10^5
// 0 <= fruits[i] < fruits.length
//
// code:

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        // Stores the frequency of each fruit type
        // inside the current sliding window
        unordered_map<int, int> mp;

        // Left boundary of the sliding window
        int l = 0;

        // Maximum valid window length
        int maxlen = 0;

        // Expand the window using the right pointer
        for (int r = 0; r < fruits.size(); r++) {

            // Add the current fruit to the window
            mp[fruits[r]]++;

            // If the window contains more than 2 fruit types,
            // shrink it from the left
            while (mp.size() > 2) {

                // Remove the fruit at the left side
                mp[fruits[l]]--;

                // If no fruits of this type remain,
                // remove the type from the map
                if (mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);

                // Move the left pointer forward
                l++;
            }

            // The current window has at most 2 fruit types
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};

int main() {

    // Example input
    vector<int> fruits = {1, 2, 3, 2, 2};

    Solution obj;

    // Call the function and print the result
    cout << obj.totalFruit(fruits);

    return 0;
}
