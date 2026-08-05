// 443. String Compression

// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Note: The characters in the array beyond the returned length do not matter and should be ignored.

 

// Example 1:

// Input: chars = ["a","a","b","b","c","c","c"]
// Output: 6
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
// After modifying the input array in-place, the first 6 characters of chars should be ["a","2","b","2","c","3"].
// Example 2:

// Input: chars = ["a"]
// Output: 1
// Explanation: The only group is "a", which remains uncompressed since it is a single character.
// After modifying the input array in-place, the first character of chars should be ["a"].
// Example 3:

// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: 4
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
// After modifying the input array in-place, the first 4 characters of chars should be ["a","b","1","2"].
 

// Constraints:

// 1 <= chars.length <= 2000
// chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) {
        // 'idx' represents the position where the compressed result
        // is written. This allows us to modify the array in-place.
        int idx = 0;
        int n = chars.size();

        // Traverse the array and process one group of identical
        // consecutive characters at a time.
        for (int i = 0; i < chars.size(); i++) {

            // Store the current character whose frequency we want to count.
            char cur = chars[i];
            int count = 0;

            // Count how many consecutive times the current character appears.
            // Move 'i' forward until a different character is found.
            while (i < n && cur == chars[i]) {
                i++;
                count++;
            }

            // If the character appears only once,
            // simply write the character to the compressed array.
            if (count == 1) {
                chars[idx++] = cur;
            }
            else {
                // If the character appears multiple times,
                // write the character first, followed by its frequency.
                chars[idx++] = cur;

                // Convert the count into a string so that each digit
                // (e.g., "12" -> '1', '2') can be stored separately.
                string digits = to_string(count);

                // Store each digit of the frequency in the array.
                for (char dig : digits) {
                    chars[idx++] = dig;
                }
            }

            // The while loop moves 'i' one position beyond the current group.
            // Decrement it so that the for loop's increment places it at the
            // first character of the next group.
            i--;
        }

        // Return the length of the compressed array.
        return idx;
    }
};