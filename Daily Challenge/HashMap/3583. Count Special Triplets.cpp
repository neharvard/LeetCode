/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/count-special-triplets/
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using map : 2 Pass Solution)
//T.C : O(2*n)
//S.C : O(n)
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int sz = nums.size();

        unordered_map<int, int>left, right;
        for(int i=0; i<sz; i++){
            right[nums[i]]++;
        }
        
        int ans = 0, mod = 1e9 + 7;
        for(int i=0; i<sz; i++){
            int check = nums[i] * 2; 
            // cout<<"check: "<<check<<endl;

            if(right[nums[i]] > 0) right[nums[i]]--;
            if(left[check] && right[check]){
                ans = (ans + (1LL * left[check] * right[check])) % mod;
                // cout<<"i: "<<i<<" num:"<<nums[i]<<" lf: "<<left[check]<<" r8: "<<right[check]<<endl;
            } 
            left[nums[i]]++;
        }

        return ans;
    }
};
