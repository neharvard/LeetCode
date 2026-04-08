/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/xor-after-range-multiplication-queries-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Straight forward simulation)
//T.C : O(n*q),  n = nums.size(), and q = queries.size()
//S.C : O(1)
class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sz = queries.size();
        int n = nums.size();
        int mod = 1e9 + 7;

        for(int i=0; i<sz; i++){
            int idx = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            for(int j=0; j<n; j++){
                if(idx >= n || idx > r) break; 
                nums[idx] = ((long long)nums[idx] * v) % mod;
                // cout<<"idx: "<<idx<<" nums: "<<nums[idx]<<endl;
                idx += k;
            }
        }

        // for(int i=0; i<n; i++) cout<<nums[i]<<" "; cout<<endl;
        
        int ans = 0;
        for(int i=0; i<n; i++){ 
            ans = (ans ^ nums[i]);
        }

        return ans;
    }
};
