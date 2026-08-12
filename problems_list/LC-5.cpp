// 5. Longest Palindromic Substring
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int expand(const string& s, int i, int j) {
        while (i >= 0 && j < static_cast<int>(s.length()) && s[i] == s[j]) {
            --i;
            ++j;
        }
        return j - i - 1;
    }

    string longestPalindrome(string s) {
        int maxlen = 1;
        int start = 0;
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            int len = max(expand(s, i, i), expand(s, i, i + 1));
            if (len > maxlen) {
                start = i - (len - 1) / 2;
                maxlen = len;
            }
        }
        return s.substr(start, maxlen);
    }
};
