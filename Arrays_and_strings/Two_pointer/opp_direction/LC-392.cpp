// 392. Is Subsequence

// Given two strings s and t, return true if s is a subsequence of t,
// or false otherwise.
//
// A subsequence is formed by deleting some (or no) characters
// from t without changing the order of the remaining characters.
//
// Example 1:
//
// Input: s = "abc", t = "ahbgdc"
// Output: true
//
// Example 2:
//
// Input: s = "axc", t = "ahbgdc"
// Output: false
//
// Constraints:
//
// 0 <= s.length <= 100
// 0 <= t.length <= 10^4
// s and t consist only of lowercase English letters.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {

        // i points to the current character we need from s
        int i = 0;

        // Traverse through t
        for (char c : t) {

            // If the current character matches s[i],
            // move to the next character of s
            if (i < s.size() && c == s[i]) {
                i++;
            }
        }

        // If we matched every character of s,
        // then s is a subsequence of t
        return i == s.size();
    }
};

int main() {

    // Example input
    string s = "abc";
    string t = "ahbgdc";

    Solution obj;

    cout << boolalpha << obj.isSubsequence(s, t);

    return 0;
}