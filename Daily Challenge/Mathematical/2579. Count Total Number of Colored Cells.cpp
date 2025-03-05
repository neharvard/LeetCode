/*
    Leetcode Link               : https://leetcode.com/problems/count-total-number-of-colored-cells
*/


//****************************************************** C++ ************************************************************************//
//Approach-1 (My Approach - Not so efficient)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
#define ll long long
    long long coloredCells(int n) {
        if (n == 1) return 1;
        else if (n == 2) return 5;
      
        ll ans = 4, cnt = 1, i = 3;
        for (;; i += 2) {
            if (cnt == n - 2) break;
            ans += (i * 2); 
            cnt++; 
            // cout<<"i:"<<i<<" ans:"<<ans<<" cnt:"<<cnt<<endl;         
        }
        ans += (i * 3);
      
        return ans;
    }
};



//Approach-2 (Using simulation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
#define ll long long
    long long coloredCells(int n) {     
        ll ans = 1, t = 1;
      
        while(t <= n){
            ans += (4*(t-1)); // 1 + 4 + 8 + 12 + 16
            t++;
        }
        return ans;
    }
};
