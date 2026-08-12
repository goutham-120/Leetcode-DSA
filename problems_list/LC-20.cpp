// 20. Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char bracket : s) {
            if (bracket == '(' || bracket == '[' || bracket == '{') {
                st.push(bracket);
            } else {
                if (st.empty()) return false;
                char opening = st.top();
                if ((bracket == ')' && opening != '(') ||
                    (bracket == ']' && opening != '[') ||
                    (bracket == '}' && opening != '{')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
