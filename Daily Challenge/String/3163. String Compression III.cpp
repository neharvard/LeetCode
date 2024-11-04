/*
    Leetcode Link               : https://leetcode.com/problems/string-compression-iii
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Simple Simulation)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    string compressedString(string word) {
        int sz = word.size();
        string ans = "";
        int freq = 0;

        for(int i=0; i<sz-1; i++){
            if(word[i] == word[i+1] && freq < 8) freq++;
            else{
                freq++; 
                ans.push_back(char(freq + '0'));
                ans.push_back(word[i]);
                freq = 0;
            }
        }  //cout<<"f:"<<freq<<endl;

        freq++;
        ans.push_back(char(freq + '0'));
        ans.push_back(word[sz-1]);
        
        return ans;
    }
};



////////   More Readable way with the same Approach
class Solution {
public:
    string compressedString(string word) {
        int sz = word.size();
        string ans = "";
        int i = 0;

        while(i < sz){
            char ch = word[i];
            int freq = 0;

            while(i < sz && freq < 9 && word[i] == ch){
                freq++; i++;
            }

            ans += to_string(freq) + ch;
        }
        
        return ans;
    }
};
