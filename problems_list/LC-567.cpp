// 567. Permutation in String

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.

 

// Example 1:

// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false
 

// Constraints:

// 1 <= s1.length, s2.length <= 104
// s1 and s2 consist of lowercase English letters.

//code:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int m = s1.length(), n = s2.length();

        // If s1 is longer than s2, it is impossible for any substring
        // of s2 to be a permutation of s1.
        if(m > n){
            return false;
        }

        // Store the frequency of each character in s1.
        vector<int> count1(26, 0);

        // Store the frequency of characters in the current window of s2.
        // This allows us to compare the two strings using character counts
        // instead of checking every possible permutation.
        vector<int> count2(26, 0);

        // Build the frequency arrays:
        // - count1 for the entire s1.
        // - count2 for the first window of s2 having the same length as s1.
        for(int i = 0; i < m; i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // If the first window already has the same character frequencies,
        // then it is a permutation of s1.
        if(count1 == count2){
            return true;
        }

        // Slide the window through s2 one character at a time.
        for(int i = m; i < n; i++){

            // Include the new character entering the window.
            count2[s2[i] - 'a']++;

            // Remove the character that is no longer inside the window,
            // keeping the window size equal to s1's length.
            count2[s2[i - m] - 'a']--;

            // Matching frequency arrays means both strings contain
            // exactly the same characters with the same counts,
            // so the current window is a permutation of s1.
            if(count1 == count2){
                return true;
            }
        }

        // No window matched the required character frequencies.
        return false;
    }
};
int main() {
    Solution solution;
    string s1 = "ab";
    string s2 = "eidbaooo";
    bool result = solution.checkInclusion(s1, s2);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}