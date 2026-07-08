/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/remove-element/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 : use container to kept the elements which isn't equal to val & then put it in the nums again 
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int sz = nums.size();
        int ans = 0;
        vector<int>vec;
        for(auto &it : nums){
            if(it != val){
                vec.push_back(it);
                ans++;
            } 
        }
        // cout<<"ans: "<<ans<<endl;

        for(int i=0, j=0; i<ans; i++, j++){
            nums[i] = vec[j];
        }
        // for(auto &it : nums) cout<<it<<" "; cout<<endl;

        return ans;
    }
};
