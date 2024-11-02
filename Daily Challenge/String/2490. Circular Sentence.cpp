/*
    Leetcode Link               : https://leetcode.com/problems/circular-sentence
*/


/**************************************************************** C++ ****************************************************************/
//Approach: BruteForce
//T.C : O(N)
//S.C : O(1)
class Solution
class Solution {
public:
    bool isCircularSentence(string s) {
        int sz = s.size();

        if(s[0] != s[sz-1]) return false;
        for(int i=0; i<sz; i++){
            if(s[i] == ' '){
                if(s[i-1] != s[i+1]) return false;
            }
        }

        return true;
    }
};
