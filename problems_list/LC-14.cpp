// 14. Longest Common Prefix
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        for (int i = 0; i < static_cast<int>(strs[0].size()); ++i) {
            for (const string& word : strs) {
                if (i >= static_cast<int>(word.size()) || word[i] != strs[0][i]) {
                    return prefix;
                }
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};
