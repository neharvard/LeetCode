/*
    Leetcode Link                : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Simple using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sz = nums.size(), mn = INT_MAX, flg = 0;
        map<int, int>mp;
        for(auto &it : nums){
            mp[it]++;
            mn = min(mn, it);
            if(it == k) flg = 1;
        } 

        if(k > mn) return -1;
       
        return (flg) ? mp.size()-1 : mp.size();
    }
};
