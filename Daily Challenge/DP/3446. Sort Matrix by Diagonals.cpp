/*
    Leetcode Link               : https://leetcode.com/problems/sort-matrix-by-diagonals/description
*/


/************************************************** C++ **************************************************/
//Approach-1 (DP + Memoization)
//T.C : O(n*m)
//S.C : O(n)
class Solution {
public:
    int m, n;
    int memo[11][11];
    vector<int>temp;

    int solve(int i, int j, vector<vector<int>>& grid){
        if(i >= m || j >= n) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        
        temp.push_back(grid[i][j]);
        solve(i+1, j+1, grid);

        return 0;
    }
    int setVal(int i, int j,vector<vector<int>>& grid, int idx){
        if(i >= m || j >= n) return 0;
        if(memo[i][j] != -1) return memo[i][j];

        grid[i][j] = temp[idx];
        memo[i][j] = temp[idx];

        setVal(i+1, j+1, grid, idx+1);
        return 0;
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(memo, -1, sizeof(memo));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                temp.clear();
                solve(i, j, grid);

                if(i == 0 && j > 0) sort(begin(temp), end(temp));  // increaseing order
                else sort(begin(temp), end(temp), greater<int>()); // decreasing order

                // cout<<"i: "<<i<<" j:"<<j<<endl;
                // for(auto &it : temp)cout<<it<<" "; cout<<endl;

                setVal(i, j, grid, 0);
            }
        }

        return grid;
    }
};



//Approach-2 (Without Map - Simulation)
//T.C : O(n^2 * logn)
//S.C : O(n)
class Solution {
public:
    int n;
    void sortDiagonal(int r, int c, vector<vector<int>>& grid, bool asc){
        int i = r, j = c;
        vector<int>v; // store the diagonal

        while(i < n && j < n){
            v.push_back(grid[i][j]);
            i++, j++;
        }

        if(asc) sort(begin(v), end(v));
        else sort(rbegin(v), rend(v));

        i = r, j = c;
        for(auto &it : v){
            grid[i][j] = it;
            i++, j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        // bottom-left decreasing
        for(int row = 0; row < n; row++){
            sortDiagonal(row, 0, grid, false);
        }

        // top-right increasing
        for(int col = 1; col < n; col++){
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};



//Approach-3 (Using Map - (i-j) as the key)
//T.C : O(n^2 * logn)
//S.C : O(n^2) map stores all elements
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int, vector<int>>mp;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[i-j].push_back(grid[i][j]);
            }
        }
        
        for(auto &it : mp){
            // cout<<"ff: "<<it.first<<" ss:"<<it.second.size()<<endl;
            if(it.first >= 0) sort(it.second.begin(), it.second.end());
            else sort(it.second.rbegin(), it.second.rend());
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x = mp[i-j].back(); //cout<<"x: "<<x<<endl;
                grid[i][j] = x;
                mp[i-j].pop_back();
            }
        }

        return grid;
    }
};
