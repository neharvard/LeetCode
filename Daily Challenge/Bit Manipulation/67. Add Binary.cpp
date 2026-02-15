/*
    Company Tags                : Adobe, Amazon, Meta, Google, Microsoft
    Leetcode Link               : https://leetcode.com/problems/add-binary
*/


/******************************************************* C++ *******************************************************/
//Approach-1: (Simple binary addition)
//T.C : O(m+n)
//S.C : O(1)
class Solution {
public:
    string addBinary(string a, string b) {
        int sz1 = a.size();
        int sz2 = b.size();

        if(sz1 < sz2) swap(a,b); // a always greater
        char carry = '0';
        string ans = "";
        int i,j;

        for(i=a.size()-1,j=b.size()-1; j>=0; i--,j--){
            // cout<<"a:"<<a[i]<<" b:"<<b[j]<<endl;
            if(a[i] == '0'){
                if(b[j] == '0'){
                    if(carry == '0') ans += '0'; //a=0,b=0,c=0
                    else ans += '1', carry = '0'; //a=0,b=0,c=1
                }
                else{ 
                   if(carry == '0') ans += '1'; //a=0,b=1,c=0
                   else ans += '0', carry = '1'; //a=0,b=1,c=1
                }
            }
            else if(a[i] == '1'){
                if(b[j] == '0'){ 
                    if(carry == '0') ans += '1'; //a=1,b=0,c=0
                    else ans += '0', carry = '1'; //a=1,b=0,c=1
                }
                else{ 
                   if(carry == '0') ans += '0',carry = '1'; //a=1,b=1,c=0
                   else ans += '1', carry = '1'; //a=1,b=1,c=1
                }
            }
        }
        // cout<<"ans: "<<ans<<" i:"<<i<<endl;
        
        while(i>=0){
            if(a[i] == '0'){
                if(carry == '1') ans += '1',carry = '0'; //a=0,c=1
                else ans += '0'; //a=0,c=0
            }
            else{
                if(carry == '1') ans += '0', carry = '1'; //a=1,c=1
                else ans += '1'; //a=1,c=0
            }
            i--;
        }

        if(carry == '1') ans += '1';
        reverse(begin(ans), end(ans));
       
        return ans;
    }
};
