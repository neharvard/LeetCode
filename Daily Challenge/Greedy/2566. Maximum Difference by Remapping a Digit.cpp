/*
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/
*/


/*************************************************************** C++ ***************************************************************/
//Approach-1 (Simple iterating on digits)
//T.C : O(log10(n))
//S.C : O(log10(n))
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num); 
        int sz = s.size();

        string temp = s;
        int flg = 0;
        char ch;
        for(int i=0; i<sz; i++){
            if(temp[i] != '9' && flg == 0){
                ch = temp[i]; flg = 1;
            }
            if(flg && temp[i] == ch) temp[i] = '9';
        }
        // cout<<"temp: "<<temp<<endl;

        flg = 0;
        for(int i=0; i<sz; i++){
            if(s[i] != '0' && flg == 0){
                ch = s[i]; flg = 1;
            }
            if(flg && s[i] == ch) s[i] = '0';
        }
        // cout<<"s: "<<s<<endl;

        int mx = stoi(temp);
        int mn = stoi(s); 
        // cout<<"mx: "<<mx<<" mn: "<<mn<<endl;
        int ans = mx - mn;

        return ans;
    }
};
