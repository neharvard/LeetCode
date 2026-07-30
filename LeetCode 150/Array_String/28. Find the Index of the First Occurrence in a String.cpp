/*
    Company Tags                - Google, Amazon, Microsoft, Facebook, Qualcomm
    Leetcode Link               - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

//Using Brute Force naive Approach
class Solution {
public:
    int strStr(string haystack, string needle) {
        int sz1 = haystack.size();
        int sz2 = needle.size();
        
        for(int i=0; i<sz1; i++){
            string s = haystack.substr(i, sz2);
            // cout<<" s:"<<s<<endl;

            if(s == needle) return i;
        }

        return -1;
    }
};
