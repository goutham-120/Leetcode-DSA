// 344. Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is a printable ascii character.

//code:
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {

        int n = s.size();

        // Use two pointers:
        // i starts from the beginning
        // n-1-i starts from the end
        // Swap the elements until we reach the middle.
        for (int i = 0; i < n / 2; i++) {

            // Swap the characters at opposite ends.
            char temp = s[i];
            s[i] = s[n - 1 - i];
            s[n - 1 - i] = temp;
        }
    }
};
int main(){
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s);

    cout << "The reversed string is: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl;

    return 0;
}