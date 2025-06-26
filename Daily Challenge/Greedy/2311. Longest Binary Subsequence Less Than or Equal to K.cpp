/*
    Leetcode Link               : https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int longestSubsequence(string s, int k) {
        long long sz = s.size();
        int ans = 0;

        long long powValue = 1, sum = 0;
        for(long long i=sz-1; i>=0; i--){
            if(s[i] == '0') ans++;
            else if(powValue <= k){
                k -= powValue;      
                // cout<<"k: "<<k<<" pow: "<<powValue<<endl;
                ans++;
            }

            if(powValue <= k) powValue *= 2;
        }

        return ans;
    }
};
