/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/jump-game-ii/description
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Optimal BruteForce)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0, coverage = 0, lastJump = 0;
        int dest = sz - 1;

        if(sz == 1) return ans;

        for(int i=0; i<sz; i++){
            coverage = max(coverage, i+nums[i]);
            // cout<<"cov:"<<coverage<<" ls:"<<lastJump<<" i:"<<i<<endl;

            if(i == lastJump){
                lastJump = coverage;
                ans++;

                if(coverage >= dest) return ans;
            }       
        }

        return ans;
    }
};
