// 49. Group Anagrams

// Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]

// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Explanation:

// There is no string in strs that can be rearranged to form "bat".
// The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
// The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
// Example 2:

// Input: strs = [""]

// Output: [[""]]

// Example 3:

// Input: strs = ["a"]

// Output: [["a"]]

 

// Constraints:

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Stores the final groups of anagrams
        vector<vector<string>> v;

        // Key = frequency signature of a string
        // Value = all strings having the same frequency signature
        unordered_map<string, vector<string>> mp;

        // Process every string
        for (string& s : strs) {

            // Count frequency of each lowercase letter
            vector<int> cnt(26, 0);

            for (char c : s) {
                cnt[c - 'a']++;
            }

            // Create a unique key using the frequency array
            // Anagrams will have exactly the same key
            string k;

            for (int i = 0; i < 26; i++) {
                k += to_string(cnt[i]) + '@';
            }

            // Put the string into the group corresponding to its key
            mp[k].push_back(s);
        }

        // Extract all anagram groups from the hash map
        for (auto& cnt : mp) {
            v.push_back(cnt.second);
        }

        return v;
    }
};
int main() {
    Solution solution;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = solution.groupAnagrams(strs);

    // Print the result
    for (const auto& group : result) {
        cout << "[";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}