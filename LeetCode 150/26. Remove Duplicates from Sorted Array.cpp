/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply BruteForce)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>st;
        for(auto &it : nums) st.insert(it);

        int ans = st.size();
        nums.assign(st.begin(),st.end());

        return ans; 
    }
};

//Approach-2 (Two Pointer)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int sz = nums.size();
        int ans = 1;
        for(int i=0,j=i+1; i<j && j<sz; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
                ans++;
            }
        }

        return ans; 
    }
};
