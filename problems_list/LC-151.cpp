// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 104
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.
 

// Follow-up: If the string data type is mutable in your language, can you solve it in-place with O(1) extra space?

//code:
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();

        // Reverse the entire string first.
        // This automatically places the words in reverse order,
        // but each individual word also becomes reversed.
        reverse(s.begin(), s.end());

        // Traverse the reversed string to extract each reversed word.
        for (int i = 0; i < n; i++) {
            string word = "";

            // Collect characters until a space or the end of the string.
            // This forms one reversed word.
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Process only if a valid word was found.
            // This skips multiple consecutive spaces.
            if (word.length() > 0) {

                // Reverse the current word to restore its original character order.
                reverse(word.begin(), word.end());

                // Append the restored word to the answer.
                // A space is added before every word for simplicity.
                ans += (' ' + word);
            }
        }

        // The answer starts with an extra space because every word
        // was prefixed with one while building the result.
        // Remove that leading space before returning.
        return ans.substr(1);
    }
};
int main() {
    Solution solution;
    string s = "  hello world  ";
    string result = solution.reverseWords(s);
    cout << "\"" << result << "\"" << endl; // Output: "world hello"
    return 0;
}