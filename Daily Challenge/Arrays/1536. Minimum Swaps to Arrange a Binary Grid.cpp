/*
    Company Tags                : Ajira Software
    Leetcode Link               : https://leetcode.com/problems/minimum-swaps-to-arrange-a-binary-grid
*/


/************************************************** C++ **************************************************/
//Approach (Siilar to Bubble Sort - Find best candidate and swap)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int>endZero(n, 0);

        for(int i=0; i<n; i++){
            int zeroCnt = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] == 0) zeroCnt++;
                else break;
            }
            endZero[i] = zeroCnt;
        }

        // for(auto &it : endZero) cout<<it<<" "; cout<<endl;

        for(int i=0; i<n; i++){
            int need = n - i - 1;
            int j = i; 
            // cout<<"i: "<<i<<" j:"<<j<<" need:"<<need<<endl;
            
            while(j < n && endZero[j] < need) j++; 
            if(j == n) return -1;

            ans += (j-i); 
            // cout<<"jj:"<<j<<" ans:"<<ans<<endl;

            while(j > i){
                swap(endZero[j], endZero[j-1]);
                j--;
            }
        }

        return ans;
    }
};
