/*
    Leetcode Link               : https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach-1 (trying at every index to find best substring)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    string answerString(string word, int numFriends) {
        string ans = "";
        int sz = word.size();
        int limit = sz - (numFriends - 1);
        if(numFriends == 1) return word;

        for(int i = 0; i<sz; i++){
            string temp = word.substr(i, limit);
            // cout<<"temp: "<<temp<<endl;
            ans = max(ans, temp);
        }
       
        return ans;
    }
};

