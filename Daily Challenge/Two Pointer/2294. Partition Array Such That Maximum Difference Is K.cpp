/*
    Leetcode Link               : https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
*/


/************************************************************ C++ ************************************************/
//Approach: Using Binary Search for checking possible value
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(nums.begin(), nums.end());

        int diff, ans = 0;
        for(int i=0,j=0; j<sz; ){
            while(j<sz && nums[j] - nums[i] <= k){
                // cout<<"i:"<<nums[i]<<" j:"<<nums[j]<<endl;
                j++;
            }
            ans++;
            i = j;
        }

        return ans;
    }
};
