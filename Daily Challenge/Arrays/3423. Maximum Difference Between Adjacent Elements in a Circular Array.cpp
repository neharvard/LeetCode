/*
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array
*/

/*********************************************************** C++ **************************************************/
//Approach - simple iteration
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int sz = nums.size();
        int ans = abs(nums[sz-1] - nums[0]);

        for(int i=0; i<sz-1; i++){
            ans = max(ans, abs(nums[i] - nums[i+1]));
        }

        return ans;
    }
};
