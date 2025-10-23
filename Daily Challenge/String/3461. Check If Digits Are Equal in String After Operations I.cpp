/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i
*/

/*************************************************************************** C++ ***************************************************************************/
//Approach (simple traverse and check)
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size() > 2){
            string temp;
            for(int i=0; i<s.size()-1; i++){
                int sum = ((s[i]-'0') + (s[i+1]-'0')) % 10;
                temp += (sum + '0');
                // cout<<"sum:"<<sum<<" t:"<<temp<<endl;
            }
            s = temp; //cout<<"s: "<<s<<endl;
        }

        if(s[0] == s[1]) return true;
        return false;
    }
};

/// More Clean Code With Same Concept
class Solution {
public:
    bool hasSameDigits(string s) {
        int sz = s.size();

        while(sz > 2){
            for(int i=0; i<sz-1; i++){
                s[i] = (((s[i]-'0') + (s[i+1]-'0')) % 10) + '0';
            }
            sz--;
        }

        return s[0] == s[1];
    }
};
