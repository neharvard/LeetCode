/*
    Leetcode Link               : https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/
*/

/*********************************************************** C++ **************************************************/
//Approach-1: Brute Force
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int sz = nums.size();
        int ans = INT_MIN;

        for(int i=0; i<sz; i++){
            for(int j=i+1; j<sz; j++){
               if(nums[i] < nums[j]) ans = max(ans, nums[j]-nums[i]);
            }
        }

        return (ans == INT_MIN) ? -1 : ans;
    }
};


//Approach-2: (Simple iteration)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int sz = nums.size();
        int ans = -1;

        int mn = nums[0];
        for(int i=0; i<sz-1; i++){
            if(mn > nums[i]) mn = nums[i];

            if(nums[i+1] > mn) ans = max(ans, nums[i+1] - mn);
         // cout<<"mn: "<<mn<<" mx: "<<nums[i+1]<<" ans:"<<ans<<endl;
        }

        return ans;
    }
};
