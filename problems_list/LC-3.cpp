/*  3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/
//code:
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution{
public:
    int lengthOfLongestSubstring(string s){
        int maxlen=0,l=0;                 //l is left end of the window
        vector<int> lastin(256,-1);       //will carry latest index of every character during loop
        for(int r=0;r<s.length();r++){   //r is the right end of the window
            char c=s[r];
            if(lastin[c]>=l){            //it means the character is already inside the window (duplicate found)
                l=lastin[c]+1;           //shifting the l towards right in a way that we cross the duplicate element as we need only unique charcters
            }
            lastin[c]=r;                 //storing latest index  of the charcter c
            maxlen=max(maxlen,r-l+1);   //obtaining the global maxlen uptil now
        }
        return maxlen;
    }

};
int main(){
    string S="abcabcbb";
    Solution s;
    cout<<"the length of longest substring in "<<S<<" which has no duplicates is :"<<s.lengthOfLongestSubstring(S)<<endl;
    return 0;
}