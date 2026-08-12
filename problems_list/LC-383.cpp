// 383. Ransom Note
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26);
        for (char ch : magazine) ++count[ch - 'a'];
        for (char ch : ransomNote) {
            if (--count[ch - 'a'] < 0) return false;
        }
        return true;
    }
};
