/*
    Leetcode Link               : https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i
*/


/************************************************** C++ **************************************************/
//Approach (Just find the minRow, maxRow, minCol and maxCol where we see 1)
//T.C : O(m * m)
//S.C : O(1)
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int mnW = INT_MAX, mxW = 0, mnH = INT_MAX, mxH = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    mnW = min(mnW, j);
                    mxW = max(mxW, j);

                    mnH = min(mnH, i);
                    mxH = max(mxH, i);
                }
            }
        }
        int width = (mxW - mnW) + 1;
        int height = (mxH - mnH) + 1;
        // cout<<"h: "<<height<<" w: "<<width<<endl;

        int ans = height * width;
        return ans;
    }
};
