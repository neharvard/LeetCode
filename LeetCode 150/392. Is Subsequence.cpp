/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/is-subsequence
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Two Pointer)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sz1 = t.size();
        int sz2 = s.size(); 

        if(sz1 == 0 && sz2 == 0) return true;

        for(int i=0,j=0; i<sz1; i++){
            // cout<<"i:"<<t[i]<<" j:"<<s[j];
            if(j<sz2 && t[i] == s[j]) j++; 

            if(j == sz2) return true;
        }

        return false;
    }
};
