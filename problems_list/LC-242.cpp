// 242. Valid Anagram
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> count(26);
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            ++count[s[i] - 'a'];
            --count[t[i] - 'a'];
        }
        return all_of(count.begin(), count.end(), [](int frequency) { return frequency == 0; });
    }
};
