/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Two Pointer)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int cnt = 1, ans = 1;
        for(int i=0, j=i+1; i<j && j<sz;j++){
            if(nums[i] == nums[j] && cnt < 2){
                i++; cnt++; ans++;
                if(i != j) nums[i] = nums[j];
            } 
            else if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                cnt = 1;
                ans++;
            }
        }

        return ans;
    }
};
