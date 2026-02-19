/*
    Company Tags                : Helix
    Leetcode Link               : https://leetcode.com/problems/count-binary-substrings
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int sz = s.size();
        int prevCnt = -1, ans = 0;

        for(int i=0; i<sz; i++){
            int temp = s[i], curCnt = 0;
            while(i<sz && temp == s[i]){
                curCnt++;
                i++;
            }
            // cout<<"cur:"<<curCnt<<" prev:"<<prevCnt<<endl;
            if(i<sz) i--;

            if(prevCnt == -1) prevCnt = curCnt;
            else{
                ans += min(prevCnt, curCnt);
                prevCnt = curCnt;
            }
        }

        return ans;
    }
};
