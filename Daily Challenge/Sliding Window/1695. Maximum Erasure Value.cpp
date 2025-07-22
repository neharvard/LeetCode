/*
    Leetcode Link               : https://leetcode.com/problems/maximum-erasure-value/
*/


/*************************************************************** C++ *************************************************/
//Approach-1 (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sz = nums.size();
        int sum = 0, ans = INT_MIN;
        unordered_map<int, int>freq;

        for(int i=0, j=0; j<sz; j++){
            if(freq[nums[j]] == 0){
                sum += nums[j];
                freq[nums[j]]++;
            }
            else{ 
                // cout<<"sum: "<<sum<<endl;
                ans = max(ans, sum);
                int ok = 0;
                while(i<sz && !ok){
                    // cout<<"num: "<<nums[i]<<" j: "<<nums[j]<<endl;
                    if(nums[i] == nums[j]) ok = 1;
                    sum -= nums[i]; 
                    freq[nums[i]]--;
                    i++;
                }

                sum += nums[j];
                freq[nums[j]]++;
            }
        }
        ans = max(ans, sum);

        return ans;
    }
};
