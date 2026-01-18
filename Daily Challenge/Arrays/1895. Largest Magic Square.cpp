/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/largest-magic-square/description/
*/


/************************************************** C++ **************************************************/
//Approach (Simulate trying all squares - optimise using prefix sums)
//T.C : O(rows * cols * min(rows, cols)^2) --> check my video for its explanation
//S.C : O(rows * cols)
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int limit = min(row, col);

        vector<vector<int>> rowSum(row, vector<int>(col));
        vector<vector<int>> colSum(row, vector<int>(col));

        for (int r = 0; r < row; r++) {
            rowSum[r][0] = grid[r][0];
            for (int c = 1; c < col; c++) {
                rowSum[r][c] = grid[r][c] + rowSum[r][c - 1];
            }
        }

        for (int c = 0; c < col; c++) {
            colSum[0][c] = grid[0][c];
            for (int r = 1; r < row; r++) {
                colSum[r][c] = grid[r][c] + colSum[r - 1][c];
            }
        }

        for (int k = limit; k >= 2; k--) {
            for (int r = 0; r + k - 1 < row; r++) {
                for (int c = 0; c + k - 1 < col; c++) {
                    int target = -1, sum;
                    bool isAllSame = true;

                    // rowSum Check
                    for (int i = r; i < r+k; i++) {
                        if (c == 0) sum = rowSum[i][c + k - 1];
                        else sum = rowSum[i][c + k - 1] - rowSum[i][c - 1];

                        if (target == -1) target = sum;
                        else {
                            if (target != sum) {
                                isAllSame = false;
                                break;
                            }
                        }
                    } 
                    if (!isAllSame) continue;

                    // colSum Check
                    for (int i = c; i < c+k; i++) {
                        if (r == 0) sum = colSum[r + k - 1][i];
                        else sum = colSum[r + k - 1][i] - colSum[r - 1][i];

                        if (target != sum) {
                            isAllSame = false;
                            break;
                        }
                    } 
                    if (!isAllSame) continue;

                    // diagonal check
                    int diag = 0, antiDiag = 0;
                    for (int i = 0; i < k; i++) {
                        diag += grid[r + i][c + i];
                        antiDiag += grid[r + i][c + k - 1 - i];
                    }
                    if (diag != target || antiDiag != target) {
                        isAllSame = false;
                    }

                    if (isAllSame) return k;
                }
            }
        }

        return 1;
    }
};
