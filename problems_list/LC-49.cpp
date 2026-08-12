// 49. Group Anagrams
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (const string& word : strs) {
            vector<int> count(26);
            for (char ch : word) ++count[ch - 'a'];
            string key;
            for (int frequency : count) key += to_string(frequency) + '@';
            groups[key].push_back(word);
        }
        vector<vector<string>> result;
        for (auto& group : groups) result.push_back(group.second);
        return result;
    }
};
