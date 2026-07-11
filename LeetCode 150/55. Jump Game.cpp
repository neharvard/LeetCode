/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/jump-game/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (kind of Two Pointer Approach)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int curr,target = sz-1;

        for(int i=sz-2; i>=0; i--){
            curr = i + nums[i];
            // cout<<"curr: "<<curr<<" tt: "<<target<<endl;

            if(curr >= target)  target = i;
        }
        // cout<<"target: "<<target<<endl;
        if(target != 0) return false;

        return true;
    }
};
