/*
    Company Tags                : Coursera, Quip
    Leetcode Link               : https://leetcode.com/problems/special-binary-string
*/


/************************************************************ C++ ******************************************************/
//Approach : (Recursion)
//T.C : ~O(n^2)
//S.C : O(n) stack space and to store special substrings
class Solution {
public:
    string solve(string s){
        int sz = s.size();

        vector<string>special;
        int start = 0, sum = 0;

        for(int i=0; i<sz; i++){
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0){ 
                // cout<<"start: "<<start;
                string inner = s.substr(start+1, i-start-1);
                // cout<<" inner: "<<inner<<endl;
                
                special.push_back('1' + solve(inner) + '0');
                start = i+1;
            }
        }

        sort(begin(special), end(special), greater<string>());
        string ans = "";

        for(auto &str : special) ans += str;
        return ans;
    }
    string makeLargestSpecial(string s) {
        return solve(s);
    }
};
