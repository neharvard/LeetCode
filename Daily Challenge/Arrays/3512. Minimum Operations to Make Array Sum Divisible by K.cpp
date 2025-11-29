/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/minimum-operations-to-make-array-sum-divisible-by-k/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simple iteration and check reminder)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &it : nums) sum += it;
        
        int ans = sum % k;
        return ans;
    }
};
