/*
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one
*/


/************************************************************************** C++ ********************************************************/
//Approach-1 (Simple simulation - Do what is beinhg asked)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int numSteps(string s) {
        int sz = s.size();
        int ans = 0, carry = 0;

        for(int i=sz-1; i>0; i--){
            int n = (s[i] - '0') + carry;
            if(n % 2){
                ans += 2, carry = 1;
            }
            else ans++;
        }
        ans += carry;

        return ans;
    }
};
