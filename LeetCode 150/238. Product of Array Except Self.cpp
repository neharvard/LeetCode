/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/product-of-array-except-self
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (using prefix & sufix concept)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int>prefix(sz), suffix(sz), ans(sz);
        
        prefix[0] = nums[0];
        for(int i=1; i<sz; i++) prefix[i] = nums[i] * prefix[i-1];

        suffix[sz-1] = nums[sz-1];
        for(int i=sz-2; i>=0; i--) suffix[i] = nums[i] * suffix[i+1];

        // for(auto &it : prefix) cout<<it<<" ";cout<<endl;
        // for(auto &it : suffix) cout<<it<<" ";cout<<endl;

        ans[0] = suffix[1];
        ans[sz-1] = prefix[sz-2]; 

        for(int i=1; i<sz-1; i++){
            ans[i] = prefix[i-1] * suffix[i+1];
        }

        return ans;
    }
};
