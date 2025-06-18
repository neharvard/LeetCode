/*
    Leetcode Link               : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
*/

/*********************************************************** C++ **************************************************/
//Approach - sorting and iterate the array, BruteForce
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int sz = nums.size();
        int arrNum = sz/3; ///cout<<"sz: "<<arrNum<<endl;

        sort(nums.begin(), nums.end());
        // for(auto &it : nums)cout<<it<<" "; cout<<endl;

        vector<vector<int>>ans(arrNum, vector<int>(3, 0));
        for(int i=0,row=0; i<sz-2; i+=3,row++){
            if(nums[i+2] - nums[i] <= k){
                ans[row][0] = nums[i];
                ans[row][1] = nums[i+1];
                ans[row][2] = nums[i+2];
            }
            else{
                ans.clear();
                return ans;
            }
        }

        return ans;
    }
};
