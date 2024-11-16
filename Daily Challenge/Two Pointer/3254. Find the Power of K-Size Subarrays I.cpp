/*
    Leetcode Link               : https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i
*/


/**************************************************************** C++ ****************************************************************/
//Approach (Using sliding window / two pointer)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        int temp = 0, ok = 0;

        for (int i = 0, j = 0; j < n; j++) {
            if (temp < k) {
                if (j > 0 && (nums[j] - nums[j - 1]) != 1) {
                    ok++;
                }
                temp++;
            }
            if (temp == k) {
                // cout<<"ok:"<<ok<<" j: "<<j<<" num: "<<nums[j]<<endl;

                if (ok == 0) ans.push_back(nums[j]);
                else ans.push_back(-1);

                if (i<n-1 && nums[i + 1] - nums[i] != 1) ok--;

                temp--;
                i++;
            }
        }

        return ans;
    }
};
