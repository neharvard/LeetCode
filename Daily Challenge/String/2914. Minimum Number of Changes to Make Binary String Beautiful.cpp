/*
    Leetcode Link               : https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful
*/


/**************************************************************** C++ ****************************************************************/
//Approach: (BruteForce, Simple iterate and count and keep track)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    int minChanges(string s) {
        int sz = s.size();
        int ans = 0;

        for(int i=0; i<sz-1; i+=2){
            if(s[i] != s[i+1]) ans++;
        }
        
        return ans;
    }
};
