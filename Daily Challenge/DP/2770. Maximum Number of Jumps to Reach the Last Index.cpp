/*
    Company Tags       : 
    Leetcode Link      : https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Recursion + Memo)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int sz;
    int memo[10000];
    int solve(vector<int>& nums, int target, int i){
        if(i == sz-1) return memo[i] = 0;

        if(memo[i] != -1) return memo[i];
        
        int ans = INT_MIN;
        for(int j=i+1; j<sz; j++){
            if(abs(nums[i] - nums[j]) <= target){
                int take = 1 + solve(nums, target, j);
                ans = max(ans, take);
            }
        }

        return memo[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        sz = nums.size();
        memset(memo, -1, sizeof(memo));
      
        int ans = solve(nums, target, 0);
        
        return ans < 0 ? -1 : ans;
    }
};


//Approach-2 (Bottom Up)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    int sz;
    int memo[10000];
    
    int maximumJumps(vector<int>& nums, int target) {
        sz = nums.size();
        memset(memo, -1, sizeof(memo));
        
        memo[sz-1] = 0;
        for(int i=sz-2; i>=0; i--){
            for(int j = i+1; j<sz; j++){
                if(abs(nums[j] - nums[i]) <= target && memo[j] != -1){
                    int take = 1 + memo[j];
                    memo[i] = max(memo[i], take);
                }
            }
        }
        
        return memo[0] < 0 ? -1 : memo[0];
    }
};
