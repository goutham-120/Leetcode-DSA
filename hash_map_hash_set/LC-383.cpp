// 383. Ransom Note

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// 1 <= ransomNote.length, magazine.length <= 105
// ransomNote and magazine consist of lowercase English letters.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        // Frequency of characters needed by ransomNote
        vector<int> a(26, 0);

        // Frequency of characters available in magazine
        vector<int> b(26, 0);

        // Count characters in ransomNote
        for (char s : ransomNote) {
            a[s - 'a']++;
        }

        // Count characters in magazine
        for (char t : magazine) {
            b[t - 'a']++;
        }

        // Check whether magazine has enough of
        // every character required by ransomNote
        for (char r : ransomNote) {
            if (a[r - 'a'] > b[r - 'a'])
                return false;
        }

        return true;
    }
};
int main() {
    Solution solution;
    string ransomNote = "aa";
    string magazine = "aab";
    bool result = solution.canConstruct(ransomNote, magazine);
    cout << "Can construct ransom note: " << (result ? "true" : "false") << endl; // Output: true   
    return 0;
}