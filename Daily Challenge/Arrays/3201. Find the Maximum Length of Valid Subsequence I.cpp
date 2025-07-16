/*
    Leetcode Link               : https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i
*/


/************************************************************ C++ *****************************************************/
//Approach (observing the condition and checking, oddCount, evenCount and alternatingCount
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int sz = nums.size();
        int od = 0, ev = 0;
    
        for(int i=0; i<sz; i++){
           if(nums[i]%2) od++;
           else ev++;
        }

        int parity = nums[0]%2;
        int alternating = 1;
        
        for(int i=1; i<sz; i++){
            int curr = nums[i] % 2;
            if(curr != parity){
                alternating++;
                parity = curr;
            }
        }

        cout<<"Od: "<<od<<" Ev: "<<ev<<" alter: "<<alternating<<endl;
        int ans = max(ev, max(od,alternating));

        return ans;
    }
};
