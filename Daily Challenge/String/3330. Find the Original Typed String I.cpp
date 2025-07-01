/*
    Leetcode Link               : https://leetcode.com/problems/find-the-original-typed-string-i
*/

/****************************************************************** C++ ******************************************************************/
//Approach (straight forward traversal)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int possibleStringCount(string word) {
        int sz = word.size();
        int ans = 1;
        
        for(int i=1; i<sz; i++){
            if(word[i] == word[i-1]) ans++;
        }

        return ans;
    }
};
