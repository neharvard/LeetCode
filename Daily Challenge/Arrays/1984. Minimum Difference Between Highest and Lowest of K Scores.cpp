/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
*/


/************************************************************ C++ ********************************************************************************/
//Approach-1 (Using sorting)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(begin(nums), end(nums));
        int ans = INT_MAX;

        for(int i=0; i<=sz-k; i++){
            ans = min(ans, (nums[i+k-1] - nums[i])) ;
        }

        return ans;
    }
};
