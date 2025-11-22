/*
      Company Tags                : META, AMAZON, GOOGLE
      Leetcode Link               : https://leetcode.com/problems/unique-length-3-palindromic-subsequences
*/

/************************************************************ C++ ************************************************************/
//Approach-1 : BruteForce
//T.C : O(n^2)
//S.C : O(n) 
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int sz = s.size();
        int ans = 0;
        unordered_set<int>check;

        for(int i=0; i<sz; i++){
            unordered_set<int>st;
            int flg = 0;
            if(check.find(s[i]) != st.end()) continue;
            check.insert(s[i]);

            for(int j=sz-1; j>i; j--){
                if(!flg && s[j] == s[i]){
                    flg = 1; continue;
                }
                if(flg) st.insert(s[j]);
            }
            // cout<<"s:"<<s[i]<<" st: "<<st.size()<<endl;
            ans += st.size();
        }

        return ans;
    }



//Approach-2
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int sz = s.size();
        int ans = 0;

        for(char ch = 'a'; ch <= 'z'; ch++){
            int leftIdx = -1;
            int rightIdx = -1;

            for(int i=0; i<sz; i++){
                if(s[i] == ch){
                    if(leftIdx == -1)leftIdx = i;
                    rightIdx = i;
                } 
            }
            
            unordered_set<char>st;
            for(int j=leftIdx+1; j<rightIdx; j++) st.insert(s[j]);

            if(rightIdx != -1){
                // cout<<"ch:"<<ch<<" left:"<<leftIdx<<" r8:"<<rightIdx<<" st:"<<st.size()<<endl;
                ans += st.size();
            } 
        }

        return ans;
    }
};



//Approach-3: (Storing first and last indices before hand
//T.C : O(n)
//S.C : O(1) - Only 26 sized always
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int sz = s.size();
        int ans = 0;

        vector<pair<int,int>>indices(26, {-1,-1});
        for(int i=0; i<sz; i++){
            char ch = s[i];
            int idx = ch - 'a'; 
            // cout<<"si:"<<s[i]<<" idx:"<<idx<<endl;

            if(indices[idx].first == -1) indices[idx].first = i;
            indices[idx].second = i;
        }

        for(auto &it : indices){
            int leftIdx = it.first;
            int rightIdx = it.second;
            
            unordered_set<char>st;
            for(int j=leftIdx+1; j<rightIdx; j++) st.insert(s[j]);

            if(rightIdx != -1){
                // cout<<"ch:"<<ch<<" left:"<<leftIdx<<" r8:"<<rightIdx<<" st:"<<st.size()<<endl;
                ans += st.size();
            } 
        }

        return ans;
    }
};
};
