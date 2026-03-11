/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/complement-of-base-10-integer
*/


/******************************************************* C++ *******************************************************/
//Approach-1
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        
        int p = 0, ans = 0;
        while(n){
            int rem = n % 2;
            if(rem == 0) ans += pow(2, p);
            n /= 2;
            p++;
        }

        return ans;
    }
};
