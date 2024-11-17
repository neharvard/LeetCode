/*
    Company Tags                : Google, Accolite, Amazon, Facebook, Goldman Sachs
    Leetcode Link               : https://leetcode.com/problems/minimum-size-subarray-sum/
    Similar GfG Link            : https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1
*/

/************************************************************ C++ ************************************************************/
//Approach - Using Sliding Window
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sz = nums.size();
        long long sum = 0;
        int ans = INT_MAX;

        for(int i=0, j=0; j<sz; j++){
            sum += nums[j];
            
            while(i < sz && sum >= target){  //cout<<"sum: "<<sum<<" i:"<<i<<" j:"<<j<<endl;
                ans = min(ans, (j - i + 1)); //cout<<"ans: "<<ans<<endl;
                sum -= nums[i];
                i++;
            }
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};
