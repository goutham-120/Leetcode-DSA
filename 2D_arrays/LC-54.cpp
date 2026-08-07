// 54. Spiral Matrix

// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 10
// -100 <= matrix[i][j] <= 100

//code:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        // Dimensions of the matrix
        int n = matrix.size(), m = matrix[0].size();

        // Four boundaries of the current layer
        int srow = 0, erow = n - 1;
        int scol = 0, ecol = m - 1;

        // Continue until all layers are traversed
        while (srow <= erow && scol <= ecol) {

            // 1. Traverse the top row (left -> right)
            for (int i = scol; i <= ecol; i++) {
                ans.push_back(matrix[srow][i]);
            }

            // 2. Traverse the right column (top -> bottom)
            // Start from srow+1 because the top-right element
            // has already been included in the previous loop.
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // 3. Traverse the bottom row (right -> left)
            // Skip if there is only one row left to avoid duplicates.
            for (int i = ecol - 1; i >= scol; i--) {
                if (srow == erow) break;
                ans.push_back(matrix[erow][i]);
            }

            // 4. Traverse the left column (bottom -> top)
            // Skip if there is only one column left to avoid duplicates.
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) break;
                ans.push_back(matrix[i][scol]);
            }

            // Move the boundaries inward to process the next inner layer
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> result = sol.spiralOrder(matrix);

    // Print the result
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}