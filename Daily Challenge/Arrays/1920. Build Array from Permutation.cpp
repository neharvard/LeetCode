/*
    Leetcode Link               : https://leetcode.com/problems/build-array-from-permutation
*/


/************************************************************ C++ ************************************************/
//Approach (BruteForce)
//T.C : O(N)
//S.C : O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int sz = nums.size();
        vector<int>ans;

        for(int i=0; i<sz; i++){
            int n = nums[nums[i]]; 
            // cout<<"n: "<<n<<endl;
            ans.push_back(n);
        }

        return ans;
    }
};
