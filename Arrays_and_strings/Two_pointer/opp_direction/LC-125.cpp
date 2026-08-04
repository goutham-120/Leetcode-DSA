// 125. Valid Palindrome

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

 

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
 

// Constraints:

// 1 <= s.length <= 2 * 105
// s consists only of printable ASCII characters.

//code:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    // Check whether the character should be considered.
    // The problem ignores spaces, punctuation, and special symbols,
    // so we only keep letters and digits for comparison.
    bool isAlphaNum(char c){
        if(c >= 'a' && c <= 'z' ||
           c >= 'A' && c <= 'Z' ||
           c >= '0' && c <= '9')
            return true;
        return false;
    }

    bool isPalindrome(string s) {

        // Start from both ends because a palindrome is checked
        // by comparing symmetric characters.
        int l = 0, r = s.length() - 1;

        while(l <= r){

            // Ignore any non-alphanumeric character on the left
            // since the problem states they should not affect the result.
            if(!isAlphaNum(s[l])){
                l++;
                continue;
            }

            // Ignore any non-alphanumeric character on the right
            // for the same reason.
            if(!isAlphaNum(s[r])){
                r--;
                continue;
            }

            // Convert both characters to lowercase before comparing
            // because uppercase and lowercase versions of the same
            // letter should be treated as equal.
            if(tolower(s[l]) != tolower(s[r]))
                return false;

            // Move inward after successfully matching this pair,
            // since these characters have already been verified.
            l++;
            r--;
        }

        // Every valid character pair matched, so the string is a palindrome.
        return true;
    }
};
int main() {
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}