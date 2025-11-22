/*
    Leetcode Link                              : https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/
    
*/

/****************************************************** C++ **************************************************************/
//Approach-1: Simple logic
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;

        for(int i=0; i<sz; i++){
            if(nums[i]%3 != 0) ans++;
        }

        return ans;
    }
};
