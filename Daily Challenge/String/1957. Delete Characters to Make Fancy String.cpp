/*
    Leetcode Link               : https://leetcode.com/problems/delete-characters-to-make-fancy-string
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Brute Force)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    string makeFancyString(string s) {
        int sz = s.size();
        string ans = "";
    
        for(int i=0; i<sz; i++){ 
            char ch = s[i];
            int cnt = 0;
            while(s[i] == ch && i<sz){ 
                cnt++; 
                i++;
            }
            if(i != sz) i--;
            if(cnt >= 2){
                ans.push_back(ch);
                ans.push_back(ch);
            }
            else ans.push_back(ch);
        }

        return ans;
       
    }
};



//Approach-2 (Brute Force)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    string makeFancyString(string s) {
        int sz = s.size();
        string ans = "";
        
        ans.push_back(s[0]);
        int freq = 1;

        for(int i=1; i<sz; i++){ 
            if(s[i] == ans.back()){
                if(freq < 2){
                    ans.push_back(s[i]);
                    freq++;
                } 
            }
            else{
                ans.push_back(s[i]);
                freq = 1;
            }
        }

        return ans;
    }
};
