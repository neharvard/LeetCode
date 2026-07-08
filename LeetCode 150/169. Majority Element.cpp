/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/majority-element/description/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sz = nums.size();
        int target = sz/2;
        unordered_map<int, int>freq;

        for(auto &it : nums){
            freq[it]++;
            if(freq[it] > target) return it;
        }

        return 0;
    }
};
