/*
    Leetcode Link                              : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/
    
*/

/****************************************************** C++ **************************************************************/
//Approach-1: Logarithmic
//T.C : O(logk)
//S.C : O(1)
class Solution {
public:
#define ll long long
    char kthCharacter(long long k, vector<int>& operations) {
        ll op = 0;
        ll val = k;
        while(val > 1){
            ll jump = ceil(log2(val)); //cout<<"Jump: "<<jump<<endl;
            val -= pow(2, jump-1); 
            op += operations[jump-1];
        }

        // cout<<"op: "<<op<<endl;
        return ('a' + (op%26));
    }
};
