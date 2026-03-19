/*
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k
*/


/************************************************** C++ **************************************************/
//Approach-1 (Brute Force) [It gives TLE]
//T.C : O(m^2 * n^2)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        // Fix the bottom-right corner at (i, j)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Sum from (0,0) to (i,j)
                int sum = 0;
                for (int m1 = 0; m1 <= i; m1++) {
                    for (int n1 = 0; n1 <= j; n1++) {
                        sum += grid[m1][n1];
                    }
                }

                if (sum <= k) count++;
            }
        }

        return count;
    }
};



//Approach-2 (Using precomputed results)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(r-1 >= 0) grid[r][c] += grid[r-1][c];
                if(c-1 >=0) grid[r][c] += grid[r][c-1];
                if(r-1 >=0 && c-1 >= 0) grid[r][c] -= grid[r-1][c-1];

                // cout<<"r:"<<r<<" c:"<<c<<" grid:"<<grid[r][c]<<endl;
                if(grid[r][c] <= k) ans++;
                else break;
            }
        }

        return ans;
    }
};
};
