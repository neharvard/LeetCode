/*
    Leetcode Link               : https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment
*/


/**************************************************************** C++ ****************************************************************/
//Approach (DP, Traverse and explore all possible paths + memoization)
//T.C : O(m*n)
//S.C : O(m*n)
// Time:  O(n * m)
// Space: O(n * m)

class Solution {
public:
    int m, n;
    int dir[4][4] = {{1,1}, {1,-1}, {-1,-1}, {-1,1}}; // order by 90 degree rotation
    int memo[501][501][2][4];

    int solve(int i, int j, bool canTurn, int d, int val, vector<vector<int>>& grid){
        int ii = i + dir[d][0];
        int jj = j + dir[d][1];

        if(ii < 0 || jj < 0 || ii >= m || jj >= n || val != grid[ii][jj]) return 0;
        if(memo[ii][jj][canTurn][d] != -1) return memo[ii][jj][canTurn][d];

        int len = 0;

        val = (val == 2) ? 0 : 2;
        int keepMoving = 1 + solve(ii, jj, canTurn, d, val, grid);
        len = max(len, keepMoving); // give the max len without any turn
        // cout<<"len1: "<<len;

        if(canTurn){
            len = max(len, 1 + solve(ii, jj, false, (d+1)%4, val, grid));
            // cout<<" len2: "<<len<<endl;
        }

        return memo[ii][jj][canTurn][d] = len;
        // return len;
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(memo, -1, sizeof(memo));

        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int d=0; d<4; d++){
                        bool canTurn = true;
                        ans = max(ans, 1 + solve(i, j, canTurn, d, 2, grid));
                    }
                }
            }
        }

        return ans;
    }
};
