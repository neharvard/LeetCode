/*
    Leetcode Link               : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i
*/

/*********************************************************** C++ **************************************************/
//Approach (Counting groups)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int sz = groups.size();
        vector<string>ans;
      
        for(int i=0; i<sz; i++){
            if(i == 0 || groups[i] != groups[i-1]){
                ans.push_back(words[i]);              
            }
        }

        return ans;
    }
};
