/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Using lo2(n) to find bits count)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int concatenatedBinary(int n) {
        long long bit = 1;
        int ans = 0, mod = 1e9 + 7;

        for(int i=n; i>=1; i--){
            int num = 0, temp = i;
            while(temp){
                int rem = temp % 2;
                temp /= 2;
                if(rem == 1){
                    num = (num + bit) % mod;
                }

                bit = (bit * 2) % mod;
            }
            // cout<<"i: "<<i<<" num:"<<num<<" bit:"<<bit<<endl;

            ans = (ans + num) % mod;
        }

        return ans;
    }
};
