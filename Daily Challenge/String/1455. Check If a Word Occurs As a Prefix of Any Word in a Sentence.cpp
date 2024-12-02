/*
    Leetcode Link               : https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (Using set and substring find)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    int isPrefixOfWord(string s, string searchWord) {
        int ans = 1, ok = 0;
        int sz1 = s.size();
        int sz2 = searchWord.size();

        for(int i=0,j=0; i<sz1; i++){
            if(s[i] == ' ') ans++;

            if(((i>0 && s[i-1] == ' ') || i==0) && s[i] == searchWord[j]){
                while(j<sz2 && i<sz1 && s[i] == searchWord[j]){
                    // cout<<s[i]<<" "<<searchWord[j]<<endl;
                    i++; j++;
                } 
                if(j == sz2){
                    ok = 1; break;
                }
                j = 0;
                if(i != sz1) i--;
            }
        }

        return (ok == 1) ? ans : -1;
    }
};
