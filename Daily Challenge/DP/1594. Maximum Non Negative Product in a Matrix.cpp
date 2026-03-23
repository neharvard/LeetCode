/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 1 (Recursion + Memoization)
//T.C : O(m*n)
//S.C : O(m*n)
class Solution {
public:
    #define ll long long 
    int row, col;
    int mod = 1e9+7;
    vector<vector<pair<ll,ll>>> memo;

    pair<ll,ll> solve(int r, int c, vector<vector<int>>& grid){
        if(r == row-1 && c == col-1) return {grid[r][c], grid[r][c]};

        if(memo[r][c] != make_pair(LLONG_MIN, LLONG_MAX)) return memo[r][c];

        ll maxVal = LLONG_MIN;
        ll minVal = LLONG_MAX;

        //go bottom
        if(r+1 < row){
            auto[bottomMax, bottomMin] = solve(r+1, c, grid);
            maxVal = max({maxVal, grid[r][c]*bottomMax, grid[r][c]*bottomMin});
            minVal = min({minVal, grid[r][c]*bottomMax, grid[r][c]*bottomMin});
        }
        
        //go right
        if(c+1 < col){
            auto[rightMax, rightMin] = solve(r, c+1, grid);
            maxVal = max({maxVal, grid[r][c] * rightMax, grid[r][c] * rightMin});
            minVal = min({minVal, grid[r][c] * rightMax, grid[r][c] * rightMin});
        }

        return memo[r][c] = {maxVal, minVal};
    }
    int maxProductPath(vector<vector<int>>& grid) {
       row = grid.size();
       col = grid[0].size();

       memo = vector<vector<pair<ll,ll>>>(row, vector<pair<ll,ll>>(col,{LLONG_MIN,LLONG_MAX}));

       auto[maxProd, minProd] = solve(0,0,grid);

       return maxProd < 0 ? -1 : maxProd % mod;
    }
};
