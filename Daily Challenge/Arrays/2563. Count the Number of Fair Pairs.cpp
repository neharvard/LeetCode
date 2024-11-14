/*
    Leetcode Link               : https://leetcode.com/problems/count-the-number-of-fair-pairs
*/


/************************************************************ C++ ************************************************/
//Approach (simple binary search trick)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long ans = 0, count;

        sort(nums.begin(), nums.end());
        // for(auto &el : nums) cout<<el<<" "; cout<<endl;

        for(int i = 0; i < n; i++){
            // auto x = lower_bound(begin(nums)+i+1, end(nums), lower - nums[i]); // this gives pointer
            // auto y = upper_bound(begin(nums)+i+1, end(nums), upper - nums[i]);

            // count = (y - i - 1) - (x - i - 1);

            int xIdx = lower_bound(begin(nums)+i+1, end(nums), lower - nums[i]) - begin(nums); // this gives Index 
            int yIdx = upper_bound(begin(nums)+i+1, end(nums), upper - nums[i]) - begin(nums);

            count = (yIdx - i - 1) - (xIdx - i - 1);
            // cout<<"num: "<<nums[i]<<" xIndex: "<<xIdx<<" yIndex: "<<yIdx<<" cnt:"<<count<<endl;

            ans += count;
        }

        return ans;
    }
};
