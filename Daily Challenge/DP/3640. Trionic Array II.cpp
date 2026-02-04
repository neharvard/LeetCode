/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/trionic-array-ii/description/
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Recursion + Memoization)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    #define ll long long
    int sz;
    vector<vector<ll>>memo;

    ll solve(int i, int trend, vector<int>& nums){
        if(i == sz){
            if(trend == 3) return 0;
            else return LLONG_MIN/2;
        }

        if(memo[i][trend] != LLONG_MIN) return memo[i][trend];

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        // skip
        if(trend == 0) skip = solve(i+1, 0, nums);

        // take
        if(trend == 3) take = nums[i];
        if(i < sz-1){
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && curr < next){
                take = max(take, curr + solve(i+1, 1, nums));
            }
            else if(trend == 1){
                if(curr < next) take = max(take, curr + solve(i+1, 1, nums));
                else if(curr > next) take = max(take, curr + solve(i+1, 2, nums));
            }
            else if(trend == 2){
                if(curr > next) take = max(take, curr + solve(i+1, 2, nums));
                else if(curr < next) take = max(take, curr + solve(i+1, 3, nums));
            }
            else if(trend == 3 && curr < next) take = max(take, curr + solve(i+1, 3, nums));
        }

        return memo[i][trend] = max(take, skip);
    }
    long long maxSumTrionic(vector<int>& nums) {
        sz = nums.size();
        memo.assign(sz+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums);
    }
};
