/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/number-of-substrings-with-only-1s
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Simple maths formula to count substrings)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numSub(string s) {
        int sz = s.size();
        int ans = 0, mod = 1e9 + 7;

        for(int i = 0; i<sz; i++){
            if(s[i] == '1'){ 
                long long oneCnt = 0;
                while(i<sz && s[i] == '1'){
                    oneCnt++, i++;
                }
                // cout<<"oneCnt: "<<oneCnt<<endl;
                long long add = (oneCnt * (oneCnt+1)) / 2;
                ans = (ans + add) % mod;
            }
        }

        return ans;
    }
};
