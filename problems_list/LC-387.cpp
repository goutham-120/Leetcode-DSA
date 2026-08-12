// 387. First Unique Character in a String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> count(26);
        for (char ch : s) ++count[ch - 'a'];
        for (int i = 0; i < static_cast<int>(s.size()); ++i) {
            if (count[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
};
