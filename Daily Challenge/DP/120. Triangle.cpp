/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/triangle
*/


/**************************************************************** C++ ****************************************************************/
//Approach - 
//T.C : 
//S.C : 
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();

        for(int i=1; i<row; i++){
            triangle[i][0] += triangle[i-1][0];
            for(int j=1; j<i; j++){ 
                // cout<<"I:"<<i<<" j:"<<j<<" tr:"<<triangle[i][j]<<endl;
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }

            triangle[i][i] += triangle[i-1][i-1];
        }

        // for(int i=0; i<row; i++){for(int j=0;j<=i;j++)cout<<triangle[i][j]<<" ";cout<<endl;}
        
        int ans = INT_MAX;
        for(int i=0; i<row; i++) ans = min(ans, triangle[row-1][i]);

        return ans;
    }
};
