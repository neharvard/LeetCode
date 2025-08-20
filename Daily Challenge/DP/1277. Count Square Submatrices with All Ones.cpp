/*
    Company Tags                : Flipkart
    Leetcode Link               : https://leetcode.com/problems/count-square-submatrices-with-all-ones
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 (simple Recursion Memoization) - Same as Maximal Square (Leetcode-221)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int m, n;
    int memo[301][301];

    int solve(int i, int j, vector<vector<int>>& matrix){
        if(i >= m || j >= n || matrix[i][j] == 0) return 0;
        
        if(memo[i][j] != -1) return memo[i][j];

        int right = solve(i, j+1, matrix);
        int diag = solve(i+1, j+1, matrix);
        int below = solve(i+1, j, matrix);

        return memo[i][j] = 1 + min({right, diag, below});
    }
    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(memo, -1, sizeof(memo));

        int ans = 0;     
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 1){
                    ans += solve(i,j,matrix);
                }
            }
        }
      
        return ans;
    }
};


//Approach - 2 (simple Bottom Up - Same as Maximal Square (Leetcode-221)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int memo[301][301] = {0};
        
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0) memo[i][j] = matrix[i][j];
                else if(matrix[i][j] == 1){
                    memo[i][j] = 1 + min({memo[i-1][j], memo[i-1][j-1], memo[i][j-1]}); //Up, Diagonal, Left
                }

                ans += memo[i][j];
            }
        }

        return ans;
    }
};
