/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/length-of-last-word/description/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (BruteForce)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int sz = s.size();
        int ans = 0, ok = 0;
        
        for(int i=sz-1; i>=0; i--){
            // cout<<"s: "<<s[i]<<endl;
            if(s[i] == ' '){
                if(!ok)continue;
                else return ans;
            } 
            else{
                ans++;
                ok = 1;
            }
        }

        return ans;
    }
};
