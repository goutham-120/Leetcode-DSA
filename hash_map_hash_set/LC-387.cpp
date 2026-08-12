// 387. First Unique Character in a String

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 

// Example 1:

// Input: s = "leetcode"

// Output: 0

// Explanation:

// The character 'l' at index 0 is the first character that does not occur at any other index.

// Example 2:

// Input: s = "loveleetcode"

// Output: 2

// Example 3:

// Input: s = "aabb"

// Output: -1

 

// Constraints:

// 1 <= s.length <= 105
// s consists of only lowercase English letters.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {

        // Frequency array for 26 lowercase English letters
        vector<int> t(26, 0);

        // Count frequency of every character
        for (char a : s) {
            t[a - 'a']++;
        }

        // Find the first character whose frequency is exactly 1
        for (int i = 0; i < s.size(); i++) {
            if (t[s[i] - 'a'] == 1) {
                return i;
            }
        }

        // No unique character found
        return -1;
    }
};
int main() {
    Solution solution;
    string s = "leetcode";
    int result = solution.firstUniqChar(s);
    cout << "Index of first unique character: " << result << endl; // Output: 0

    s = "loveleetcode";
    result = solution.firstUniqChar(s);
    cout << "Index of first unique character: " << result << endl; // Output: 2

    s = "aabb";
    result = solution.firstUniqChar(s);
    cout << "Index of first unique character: " << result << endl; // Output: -1

    return 0;
}