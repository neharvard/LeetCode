/*
    Leetcode Link                : https://leetcode.com/problems/find-missing-and-repeated-values
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple using map)
//T.C : O(n^2)
//S.C : O(n^2)
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int sz = grid.size();
        int N = (sz*sz);

        unordered_map<int,int>ump;
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                ump[grid[i][j]]++;
            }
        }

        vector<int>ans(2, -1);

        for(int i=1; i<=N; i++){
            if(!ump.count(i)){
                ans[1] = i;
            }
            else if(ump[i] == 2){
                ans[0] = i;
            }

            if(ans[0] != -1 && ans[1] != -1) break;
        }

        return ans;
    }
};
