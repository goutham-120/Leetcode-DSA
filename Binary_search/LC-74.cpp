// 74. Search a 2D Matrix

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

//code:
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // Performs Binary Search on a specific row to find the target.
    bool searchRow(vector<vector<int>> matrix, int target, int row) {
        int l = 0, r = matrix[0].size() - 1;

        // Continue searching until the search space becomes empty.
        while (l <= r) {
            int mid = l + (r - l) / 2;

            // Target found.
            if (matrix[row][mid] == target)
                return true;

            // Target lies in the right half.
            else if (target > matrix[row][mid])
                l = mid + 1;

            // Target lies in the left half.
            else
                r = mid - 1;
        }

        // Target does not exist in this row.
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        // Binary Search on the rows to determine which row
        // could possibly contain the target.
        int srow = 0, erow = matrix.size() - 1;
        int n = matrix[0].size();

        while (srow <= erow) {

            // Find the middle row.
            int mid = srow + (erow - srow) / 2;

            // If the target lies within the range of values
            // present in the current row, search only this row.
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                return searchRow(matrix, target, mid);
            }

            // If the target is greater than the last element
            // of the current row, it must be in a lower row.
            else if (target >= matrix[mid][n - 1]) {
                srow = mid + 1;
            }

            // Otherwise, the target must be in an upper row.
            else {
                erow = mid - 1;
            }
        }

        // Target is not present in any row.
        return false;
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    bool result = solution.searchMatrix(matrix, target);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}