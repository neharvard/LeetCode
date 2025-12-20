/*
    Company Tags                : Microsoft
    Leetcode Link               : https://leetcode.com/problems/delete-columns-to-make-sorted/
*/
//Approach-1: (Just compare words by words) - O(n*k)
//TC: O(n^2)
//SC: O(n)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int ans = 0;

        for(int i=0; i<col; i++){
            string temp = "";
            for(int j=0; j<row; j++){
                temp += strs[j][i];
            }
            string s = temp;
            sort(begin(s), end(s));
            // cout<<"t: "<<temp<<" s: "<<s<<endl;
            if(temp != s) ans++;
        }

        return ans;
    }
};


//Approach-2: (Just compare letter by letter) - O(n*k)
//n = number of words in input
//k = length of each word (same for each word)
//TC: O(n^2)
//SC: O(1)
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int row = strs.size();
        int col = strs[0].size();
        int ans = 0;

        for(int i=0; i<col; i++){
            char prev = strs[0][i];
            for(int j=1; j<row; j++){
                char curr = strs[j][i];
                // cout<<"prev: "<<prev<<" curr: "<<curr<<endl;
                if(curr >= prev) prev = curr;
                else{
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
