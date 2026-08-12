// 205. Isomorphic Strings
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> mapping;
        unordered_set<char> mapped;
        for (int i = 0; i < static_cast<int>(s.length()); ++i) {
            if (mapping.count(s[i])) {
                if (mapping[s[i]] != t[i]) return false;
            } else {
                if (mapped.count(t[i])) return false;
                mapping[s[i]] = t[i];
                mapped.insert(t[i]);
            }
        }
        return true;
    }
};
