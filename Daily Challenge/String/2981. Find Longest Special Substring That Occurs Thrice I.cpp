/*
   
    Leetcode Link               : https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i
                                
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force - Try all possible substrings)
//T.C : O(n^3)
//S.C : O(n^2), total substrings
class Solution {
public:
    int maximumLength(string s) {
        int sz = s.size();
        unordered_map<string, int>freq;
        
        for(int i=0; i<sz; i++){
            string temp;
            for(int j=i; j<sz; j++){
                if(s[j] != s[i]) break;

                temp += s[j];
                freq[temp]++;
            }
        }

        int ans = -1;
        for(auto &el : freq){
            // cout<<el.first<<" "<<el.second<<endl;
            if(el.second >= 3){
                int n = el.first.size();
                ans = max(ans, n);
            }
        }

        return ans;
    }
};
