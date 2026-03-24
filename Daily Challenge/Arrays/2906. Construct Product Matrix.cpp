/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/construct-product-matrix/description/
*/


/************************************************** C++ **************************************************/
//Approach - Suffix and Prefix Products
//T.C : O(n*m)
//S.C : O(n*m) , for the result to be returned
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int mod = 12345;

        vector<vector<int>>ans(row, vector<int>(col));
        long long int suffix = 1;
        
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                ans[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % mod;
            }
        }
        
        long long int prefix = 1;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                ans[i][j] = (prefix * ans[i][j]) % mod;
                prefix = (prefix * grid[i][j]) % mod;
            }
        }

        return ans;
    }
};
