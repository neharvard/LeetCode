/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/binary-prefix-divisible-by-5
*/

/****************************************************************************** C++ ******************************************************************************/
//Approach (Using bit concept and modular arithmetic)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int sz = nums.size();
        vector<bool>ans(sz, true);

        int curr = 0;
        for(int i=0; i<sz; i++){
            curr = (curr * 2 + nums[i]) % 5;
            // cout<<"curr: "<<curr<<endl;

            if(curr != 0) ans[i] = false;
        }

        return ans;
    }
};
