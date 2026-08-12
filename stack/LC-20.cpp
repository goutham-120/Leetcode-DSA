// 20. Valid Parentheses

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

// Example 5:

// Input: s = "([)]"

// Output: false

 

// Constraints:

// 1 <= s.length <= 104
// s consists of parentheses only '()[]{}'.

//code:
#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValid(string s) {

        // Stack stores opening brackets
        stack<char> st;

        for (char t : s) {

            // If it is an opening bracket,
            // push it onto the stack
            if (t == '{' || t == '[' || t == '(') {
                st.push(t);
            }
            else {

                // Closing bracket without a corresponding
                // opening bracket
                if (st.empty()) {
                    return false;
                }

                // Get the most recently added opening bracket
                char top = st.top();

                // Check whether the opening and closing
                // brackets match
                if ((t == ')' && top == '(') ||
                    (t == '}' && top == '{') ||
                    (t == ']' && top == '[')) {

                    // Matching pair found
                    st.pop();
                }
                else {
                    // Wrong type of bracket
                    return false;
                }
            }
        }

        // Stack must be empty, meaning every opening
        // bracket had a matching closing bracket
        return st.empty();
    }
};
int main() {
    Solution solution;
    string s = "([])";
    cout << "Is the string \"" << s << "\" valid? " << (solution.isValid(s) ? "true" : "false") << endl;
    return 0;
}