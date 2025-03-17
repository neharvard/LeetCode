/*
    Leetcode Link               : https://leetcode.com/problems/divide-array-into-equal-pairs
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto &it : nums) freq[it]++;

        bool ans = true;
        for(auto &it : freq){
            if(it.second % 2) {
                ans = false;
                break;
            }
        }

        return ans;
    }
};
