/*
    Company Tags                               : 
    Leetcode Link                              : https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles
    
*/


/****************************************************** C++ **************************************************************/
//Approach - (Just find all possible intersections and best square side from them)
//T.C : O(n * n)
//S.C : O(1)
class Solution {
public:
    #define ll long long int
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int sz = bottomLeft.size();
        ll mxSide = 0;

        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
                // width
                int topRightX = min(topRight[i][0], topRight[j][0]);
                int bottomLeftX = max(bottomLeft[i][0], bottomLeft[j][0]);
                int width = topRightX - bottomLeftX;

                // height
                int topRightY = min(topRight[i][1], topRight[j][1]);
                int bottomLeftY = max(bottomLeft[i][1], bottomLeft[j][1]);
                int height = topRightY - bottomLeftY;

                ll side = min(width, height);
                mxSide = max(mxSide, side);
            }
        }
        
        return (mxSide * mxSide);
    }
};
