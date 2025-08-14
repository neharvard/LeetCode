/*
    Leetcode Link               : https://leetcode.com/problems/largest-3-same-digit-number-in-string
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Greedy)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string largestGoodInteger(string num) {
        int sz = num.size();
        string ans = "";
        char temp;
        int ok = 0;

        for(int i=0; i<sz; i++){
            int cnt = 0;
            char ch = num[i];

            while(i<sz && num[i] == ch){
                cnt++;
                i++;
            }
            if(i != sz) i--;
            // cout<<"i: "<<i<<" ch: "<<ch<<" cnt: "<<cnt<<" s:"<<ans<<endl;

            if(cnt >= 3){
               if(!ok) temp = ch, ok = 1;
               else temp = max(temp, ch);
            }
        }
        if(ok) ans += temp, ans += temp, ans += temp;

        return ans;
    }
};
