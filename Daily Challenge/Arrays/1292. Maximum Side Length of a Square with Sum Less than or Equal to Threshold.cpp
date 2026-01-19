/*
    Company Tags                   : DE Shaw
    Leetcode Link                  : https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using 2D Prefix Sum and finding best side square)
//T.C : O(rows * cols * min(rows, cols))
//S.C : O(rows * cols)
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row =  mat.size();
        int col = mat[0].size();
        int side = min(row, col); 

        vector<vector<int>>rowSum(row, vector<int>(col));

        for(int r=0; r<row; r++){
            rowSum[r][0] = mat[r][0];
            for(int c=1; c<col; c++){
                rowSum[r][c] = mat[r][c] + rowSum[r][c-1];
            }
        }

        for(int k=side; k>0; k--){
            for(int r=0; r+k-1<row; r++){
                for(int c=0; c+k-1<col; c++){
                    bool isCheck = true;
                    int sum = 0;

                    // rowSum check
                    for(int i=r; i<r+k; i++){
                        if(c == 0) sum += rowSum[i][c+k-1];
                        else sum += (rowSum[i][c+k-1] - rowSum[i][c-1]);

                        if(sum > threshold){
                            isCheck = false;
                            break;
                        }
                    }

                    if(isCheck) return k;
                }
            }
        }

        return 0;
    }
};
