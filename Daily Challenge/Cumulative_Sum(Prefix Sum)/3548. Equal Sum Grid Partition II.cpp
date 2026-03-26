/*
    Company Tags                   : 
    Leetcode Link                  : https://leetcode.com/problems/equal-sum-grid-partition-ii/description/
*/


/************************************************************ C++ *****************************************************/
//Approach (Using prefix sum)
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    #define ll long long
    ll totalSum = 0;
    
    bool checkHorCut(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        unordered_set<ll>st;

        ll top = 0, bottom = 0;
        for(int i=0; i<row-1; i++){
            for(int j=0; j<col; j++){
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            bottom = totalSum - top;
            ll diff = top - bottom;

            if(diff == 0) return true;
            if(diff == grid[0][0]) return true;
            if(diff == grid[i][col-1]) return true;
            if(diff == grid[i][0]) return true;
            if(i>0 && col>1 && st.count(diff)) return true;
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++) totalSum += grid[i][j];
        }

        // for horizontal cut check
        if(checkHorCut(grid)) return true;
        reverse(begin(grid), end(grid));
        if(checkHorCut(grid)) return true;

        // for vertical cut check, using same horizontal cut method
        reverse(begin(grid), end(grid)); // to get original grid
        vector<vector<int>>transposeGrid(col, vector<int>(row));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                transposeGrid[j][i] = grid[i][j];
            }
        }

        if(checkHorCut(transposeGrid)) return true;
        reverse(begin(transposeGrid), end(transposeGrid));
        if(checkHorCut(transposeGrid)) return true;

        return false;
    }
};
