/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/
*/


/****************************************************************** C++ **********************************************************/
//Approach-1 (Recursion + Memoization)
//T.C : O(one * zero * limit)
//S.C : O(one * zero)
class Solution {
public:
    int mod = 1e9+7;
    int memo[201][201][2];

    int solve(int zeroCnt, int oneCnt, bool isLastOne,int limit){
        if(zeroCnt == 0 && oneCnt == 0) return 1; // got one stable binary arr

        if(memo[zeroCnt][oneCnt][isLastOne] != -1) {
            return memo[zeroCnt][oneCnt][isLastOne];
        }
        
        int ans = 0;

        // Explore Zero
        if(isLastOne == true){
            for(int len = 1; len <= min(zeroCnt, limit); len++){
                ans = (ans + solve(zeroCnt-len, oneCnt, false, limit)) % mod;
            }
        }
        else{ // Explore One
            for(int len = 1; len <= min(oneCnt, limit); len++){
                ans = (ans + solve(zeroCnt, oneCnt-len, true, limit)) % mod;
            }
        }

        return memo[zeroCnt][oneCnt][isLastOne] = ans;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        memset(memo,-1,sizeof(memo));

        int startWithOne = solve(zero, one, true, limit);
        int startWithZero = solve(zero, one, false, limit);

        return (startWithOne + startWithZero) % mod;
    }
};
