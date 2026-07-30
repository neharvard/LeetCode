/*
    Company Tags                : Amazon, Facebook, Google
    Question on GfG             : Find triplets with zero sum (https://practice.geeksforgeeks.org/problems/find-triplets-with-zero-sum/1)
    Leetcode Qn Link            : https://leetcode.com/problems/3sum/
*/


/************************************************ C++ ************************************************/
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>>ans;
    void twoSum(int target, int i, int j, vector<int>& nums){
        while(i < j){
            int sum = nums[i] + nums[j];
            // cout<<"i:"<<i<<" ni:"<<nums[i]<<" j:"<<j<<" nj:"<<nums[j]<<" sum:"<<sum<<endl;

            if(sum > target) j--;
            else if(sum < target) i++;
            else{
                while(i<j && nums[i] == nums[i+1]) i++;
                while(i<j && nums[j] == nums[j-1]) j--;

                ans.push_back({-target, nums[i], nums[j]});
                i++, j--;
            }

           
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for(auto &it : nums) cout<<it<<" ";  cout<<endl;

        for(int i=0; i<sz-2; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;

            int target = -nums[i];
            // cout<<"i: "<<i<<" target:"<<target<<endl;

            twoSum(target, i+1, sz-1, nums);
        }

        return ans;
    }
};
