/*
    Company Tags                : Adobe, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply check by the formula)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int sz = dimensions.size();
        int ans = 0;
        double mxDiag = 0;

        for(int i=0; i<sz; i++){
            int len =  dimensions[i][0];
            int width = dimensions[i][1];

            double diag = sqrt((len*len) + (width*width));
            // cout<<"diag: "<<diag<<" mx:"<<mxDiag<<endl;

            if(diag > mxDiag){
                mxDiag = diag;
                ans =  (len * width);
            }
            else if(diag == mxDiag) ans = max(ans, (len*width));
        }

        return ans;
    }
};

/// TC- O(N), SC- O(1)
