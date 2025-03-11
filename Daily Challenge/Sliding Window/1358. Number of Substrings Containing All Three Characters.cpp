/*
    Leetcode Link               : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
*/


//Approach (Sliding Window Khandani Template)
//T.C : O(2*n) ~ O(n)
//S.C : O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int sz = s.size();
        int ans = 0, i = 0, j = 0;
        unordered_map<char,int>mp(3);
        
        while(j < sz ){
            mp[s[j]]++;
            // cout<<mp['a']<<" "<<mp['b']<<" "<<mp['c']<<endl;
            while(mp['a'] > 0 && mp['b']>0 && mp['c']>0){
                ans += sz - j;
                mp[s[i]]--;
                i++; 
            }
            j++;
        }

        return ans;
    }
};
