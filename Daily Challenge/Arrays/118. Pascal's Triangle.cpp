/*
    Company Tags                : Adobe, Amazon
    Leetcode Link               : https://leetcode.com/problems/pascals-triangle/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply just like Pascal triangle is formed)
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);

        for(int i=0; i<numRows; i++){
            ans[i] = vector<int>(i+1, 1);
            for(int j=1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }

        return ans;
    }
};
