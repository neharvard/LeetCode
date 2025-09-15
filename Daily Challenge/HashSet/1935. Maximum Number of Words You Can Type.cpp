/*
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-words-you-can-type
*/


/************************************************************ C++ ************************************************/
//Approach: Using set 
//T.C : O(N + M)
//S.C : O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int totalWord = 0;

        set<char>st;
        for(auto &it : brokenLetters) st.insert(it);

        bool ok = true;
        for(auto &it: text){
            if(it >= 'a' && it <= 'z'){
                if(st.find(it) != st.end()) ok = false;
            }
            if(it == ' '){
                if(ok) totalWord++;
                ok = true;
            }
        }
        if(ok) totalWord++;

        return totalWord;
    }
};
