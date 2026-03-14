/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Khandani Backtracking remplate - storing all possible strings)
//T.C : O(n * 3 * 2^(n-1)) ~= O(n*2^n)
//S.C : O(n * 2^n) , total 2^n strings eaching having length n
class Solution {
public:
    void solve(string &curr, vector<string>&ans, int n){
        if(curr.size() == n){
            ans.push_back(curr);
            return;
        }

        for(char ch='a'; ch<='c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;

            curr.push_back(ch); // do;
            solve(curr, ans, n); // explore
            curr.pop_back(); // undo
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        vector<string>ans;
        solve(curr, ans, n); 

        if(k > ans.size()) return "";
        return ans[k-1];
    }
};
