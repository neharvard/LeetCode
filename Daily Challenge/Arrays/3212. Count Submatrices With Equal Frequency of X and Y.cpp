/*
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y
    Same as Leetcode 3070       : https://www.youtube.com/watch?v=sWNfDG1kyrA
*/


/************************************************** C++ **************************************************/
//Approach (Using Same Cumulative Sum of Submatrices Concept we used in Leetcode 3070)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>>cumSumX(row,vector<int>(col));
        vector<vector<int>>cumSumY(row,vector<int>(col));
        int ans = 0;

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                cumSumX[r][c] = (grid[r][c] == 'X');
                cumSumY[r][c] = (grid[r][c] == 'Y');

                if(r-1 >= 0){
                    cumSumX[r][c] += cumSumX[r-1][c];
                    cumSumY[r][c] += cumSumY[r-1][c];
                }
                if(c-1 >= 0){
                    cumSumX[r][c] += cumSumX[r][c-1];
                    cumSumY[r][c] += cumSumY[r][c-1];
                }
                if(r-1 >= 0 && c-1 >= 0){
                    cumSumX[r][c] -= cumSumX[r-1][c-1];
                    cumSumY[r][c] -= cumSumY[r-1][c-1];
                }

                if(cumSumX[r][c] == cumSumY[r][c] && cumSumX[r][c] > 0) ans++;
            }
        }

        return ans;
    }
};
