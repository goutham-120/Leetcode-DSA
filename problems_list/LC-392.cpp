// 392. Is Subsequence
//
// Given two strings s and t, return true if s is a subsequence of t,
// or false otherwise.

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;

        for (char c : t) {
            if (i < s.size() && c == s[i]) {
                i++;
            }
        }

        return i == s.size();
    }
};

int main() {
    string s = "abc";
    string t = "ahbgdc";
    Solution obj;

    cout << boolalpha << obj.isSubsequence(s, t);
    return 0;
}
