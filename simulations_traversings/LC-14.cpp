// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

 

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
 

// Constraints:

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] consists of only lowercase English letters if it is non-empty.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    // Checks whether character k appears at index i
    // in every string
    bool isvalid(char k, int i, vector<string>& strs) {

        for (const string& t : strs) {

            // If the string is too short OR
            // the character at index i is different
            if (i >= t.size() || t[i] != k)
                return false;
        }

        // Character is common at this index
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        string s;

        // Use the first string as the reference
        for (int i = 0; i < strs[0].size(); i++) {

            // Check if this character exists at the
            // same position in every string
            if (isvalid(strs[0][i], i, strs))
                s += strs[0][i];

            // First mismatch means the common prefix ends
            else
                break;
        }

        return s;
    }
};
int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    string result = solution.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << result << endl; // Output: "fl"
    return 0;
}