// Approach - 1
class Solution {
public:
    int row, col;
    bool checkMat(int i, int j, vector<vector<int>>& mat){
        // row check
        for(int c=0; c<col; c++){
            if(c!=j && mat[i][c] != 0) return false;
        }

        // col check
        for(int r=0; r<row; r++){
            if(r!=i && mat[r][j] != 0) return false;
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();
        int ans = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    if(checkMat(i, j, mat)) ans++;
                }            
            }
        }

        return ans;
    }
};



// Approach - 2
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int rowSz = mat.size();
        int colSz = mat[0].size();
        vector<int>rowCnt(rowSz),colCnt(colSz);
        for(int i=0;i<rowSz;i++){
            for(int j=0;j<colSz;j++){
                if(mat[i][j]){
                    rowCnt[i]++; colCnt[j]++;
                }
            }
        }
        for(int i=0;i<rowSz;i++){
            for(int j=0;j<colSz;j++){
                if(mat[i][j] && rowCnt[i]==1 && colCnt[j]==1){
                   ans++;
                }
            }
        }
        return ans;
    }
};
