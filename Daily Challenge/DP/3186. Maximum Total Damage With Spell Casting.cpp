/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/maximum-total-damage-with-spell-casting
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 - Recursion + Memoization
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    #define ll long long
    #define pb push_back
    unordered_map<ll, ll>freq;
    int sz;
    vector<ll>memo;
    
    ll solve(vector<ll>& unique, int i){
        if(i >= sz) return 0;

        if(memo[i] != -1) return memo[i];

        // skip
        ll skip = solve(unique, i+1);

        // take
        int j = lower_bound(begin(unique)+i+1, end(unique), unique[i]+3) - begin(unique); // idx of next nums
        ll take = (unique[i] * freq[unique[i]]) + solve(unique, j);

        return memo[i] = max(take, skip);
    }
    long long maximumTotalDamage(vector<int>& power) {
        for(auto &it : power) freq[it]++;

        vector<ll>unique;
        for(auto &it : freq) unique.pb(it.first);
        
        sort(begin(unique), end(unique));
        sz = unique.size();

        memo.assign(sz, -1);

        return solve(unique, 0);
    }
};
