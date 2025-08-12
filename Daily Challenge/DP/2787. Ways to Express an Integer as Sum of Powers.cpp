/*
    Leetcode Link               : https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(n*n), assuming that num can go till n in worst case (At max states = t[n][n])
//S.C : O(n*n), assuming that num can go till n in worst case (we took t[n][n])
class Solution {
public:
    #define ll long long int
    int mod = 1e9 + 7;
    int memo[301][301];

    int solve(int n, int num, int x){
        if(n == 0) return 1;

        int currPower = (int)pow(num, x) % mod;
        if(currPower > n) return 0;

        if(memo[n][num] != -1) return memo[n][num];

        int take = solve(n - currPower, num+1, x);
        int skip = solve(n, num+1, x);

        return memo[n][num] = (take + skip) % mod;
    }
    int numberOfWays(int n, int x) {
        memset(memo, -1, sizeof(memo));

        return solve(n, 1, x);
    }
};
