/*
    Leetcode Link               : https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer
*/

/*********************************************************** C++ **************************************************/
//Approach-1 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0, neg = 0, ans;

        for(auto &it : nums){
            if(it < 0) neg++;
            else if(it > 0) pos++;
        }
        ans = max(pos,neg);

        return ans;
    }
};
