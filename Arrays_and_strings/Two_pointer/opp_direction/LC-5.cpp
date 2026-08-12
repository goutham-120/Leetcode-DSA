// 5. Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:

    // Expand around the center (i, j)
    // and return the length of the palindrome
    int expand(string s, int i, int j) {

        // Keep expanding while:
        // 1. i is inside the string
        // 2. j is inside the string
        // 3. characters on both sides are equal
        while (i >= 0 && j < s.length() && s[i] == s[j]) {

            i--;
            j++;
        }

        // i and j have moved one position beyond
        // the actual palindrome
        return j - i - 1;
    }

    string longestPalindrome(string s) {

        // Length of the longest palindrome found so far
        int maxlen = 1;

        // Starting index of the longest palindrome
        int start = 0;

        // Consider every position as a possible center
        for (int i = 0; i < s.length(); i++) {

            // Odd-length palindrome
            // Example: "aba"
            int len1 = expand(s, i, i);

            // Even-length palindrome
            // Example: "abba"
            int len2 = expand(s, i, i + 1);

            // Take the longer palindrome
            int len = max(len1, len2);

            // If we found a longer palindrome
            if (len > maxlen) {

                // Calculate its starting index
                start = i - (len - 1) / 2;

                maxlen = len;
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, maxlen);
    }
};