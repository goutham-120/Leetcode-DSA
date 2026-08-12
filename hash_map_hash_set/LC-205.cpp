// 205. Isomorphic Strings

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

// Example 1:

// Input: s = "egg", t = "add"

// Output: true

// Explanation:

// The strings s and t can be made identical by:

// Mapping 'e' to 'a'.
// Mapping 'g' to 'd'.
// Example 2:

// Input: s = "f11", t = "b23"

// Output: false

// Explanation:

// The strings s and t can not be made identical as '1' needs to be mapped to both '2' and '3'.

// Example 3:

// Input: s = "paper", t = "title"

// Output: true

 

// Constraints:

// 1 <= s.length <= 5 * 104
// t.length == s.length
// s and t consist of any valid ascii character.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        // If lengths are different, they cannot be isomorphic
        if (s.length() != t.length())
            return false;

        // Maps each character of s to a character of t
        unordered_map<char, char> mp;

        // Keeps track of characters in t that are already mapped
        unordered_set<char> used;

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            // If 'a' already has a mapping
            if (mp.count(a)) {

                // The existing mapping must match 'b'
                if (mp[a] != b)
                    return false;
            }
            else {

                // 'b' cannot already be mapped to another character
                // because the mapping must be one-to-one
                if (used.count(b))
                    return false;

                // Create the mapping a -> b
                mp[a] = b;

                // Mark b as already used
                used.insert(b);
            }
        }

        return true;
    }
};
int main() {
    Solution solution;
    string s = "egg";
    string t = "add";
    bool result = solution.isIsomorphic(s, t);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}