/*
    Company Tags                : Google
    Leetcode Link               : https://leetcode.com/problems/count-submatrices-with-all-ones
*/


/************************************************** C++ **************************************************/
//Approach (Using same concept as finding subarrays having all 1s in a 1D Array)
//T.C : O(m * m * n)
//S.C : O(n)class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int ans = 0;

        for(int startRow = 0; startRow < m; startRow++){
            vector<int>temp(n, 1);
            for(int endRow = startRow; endRow < m; endRow++){
                for(int col = 0; col < n; col++){
                    temp[col] = temp[col] & mat[endRow][col];
                }

                int cnt = 0;
                for(auto &it : temp){
                    if(it == 1) cnt++;
                    else cnt = 0;
                    ans += cnt;
                }
            }
        }

        return ans;
    }
};
