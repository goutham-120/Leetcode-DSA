// 242. Valid Anagram

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"

// Output: true

// Example 2:

// Input: s = "rat", t = "car"

// Output: false

 

// Constraints:

// 1 <= s.length, t.length <= 5 * 104
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {

        // If lengths are different, they cannot be anagrams
        if (s.size() != t.size())
            return false;

        // Frequency array for 26 lowercase English letters
        vector<int> temp(26, 0);

        for (int i = 0; i < s.size(); i++) {

            // Count the character from s
            temp[s[i] - 'a']++;

            // Remove the character from t
            temp[t[i] - 'a']--;
        }

        // Every frequency should be 0 if s and t are anagrams
        for (int val : temp) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};
int main() {
    Solution solution;
    string s = "anagram";
    string t = "nagaram";
    bool result = solution.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Output: true

    s = "rat";
    t = "car";
    result = solution.isAnagram(s, t);
    cout << (result ? "true" : "false") << endl; // Output: false

    return 0;
}