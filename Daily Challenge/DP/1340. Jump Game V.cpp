/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/jump-game-v/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*d)
//S.C : O(n)
class Solution {
public:
    int sz;
    int memo[1001];
    int solve(vector<int>& arr, int i, int d){
        if(i >= sz) return 0;

        if(memo[i] != -1) return memo[i];
        
        int ans = 1;
        // left side -> i-1,i-2...i-d
        for(int j=i-1; j>=max(0,i-d); j--){
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(arr,j,d));
        }

        // right side -> i+1,i+2...i+d
        for(int j=i+1; j <= min(sz-1,i+d); j++){
            if(arr[j] >= arr[i]) break;
            ans = max(ans, 1 + solve(arr, j, d));
        }

        return memo[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        sz = arr.size();
        memset(memo,-1,sizeof(memo));

        int ans = 0;

        for(int i=0; i<sz; i++){
            ans = max(ans, solve(arr, i, d));
        }

        return ans;
    }
};
