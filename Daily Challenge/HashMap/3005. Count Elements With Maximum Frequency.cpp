/*
    Leetcode Link               : https://leetcode.com/problems/count-elements-with-maximum-frequency
*/


/************************************************************ C++ ************************************************/
//Approach: Using unordered_map to get the maximum frequency
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int>freq;
        int mx = 0;

        for(auto &it : nums){
            freq[it]++;
            mx  = max(mx, freq[it]);
        }
        
        int ans = 0;
        for(auto &it : freq){
            if(it.second == mx) ans += mx;
        }

        return ans;
    }
};
