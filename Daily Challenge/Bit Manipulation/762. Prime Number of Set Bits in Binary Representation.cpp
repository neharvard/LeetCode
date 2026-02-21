/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation
*/

/****************************************************************************** C++ ******************************************************************************/
//Approach (Using bit concept and Prime number found logic)
//T.C : O((R−L)∗Log(R)∗Sqrt(Log(R)))
//S.C : O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        
        for(int i=left; i<=right; i++){
            int n = i, bitCnt = 0;
            while(n){
                if(n % 2) bitCnt++; 
                n /= 2; 
            }
            // cout<<"i: "<<i<<" bit: "<<bitCnt;

            bool ok = true;
            for(int j=2; j*j <= bitCnt; j++){
                if(bitCnt % j == 0){
                    ok = false;
                    break;
                }
            } 

            if(ok && bitCnt != 1) ans++;
        }

        return ans;
    }
};
