/*
    Leetcode Link               : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid
*/


/********************************************************************** C++ **********************************************************************/
//Approach: (Using stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(s[i]);
            else {
                if (!st.empty()) st.pop();
                else cnt++;
            }
        }
        return st.size() + cnt;
    }
};
