/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/keep-multiplying-found-values-by-two/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply iteration)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st;
        for(auto &it : nums) st.insert(it);
        
        // int ans = original;
        // while(1){
        //     if(st.find(original) == st.end()) break;
        //     ans *= 2;
        //     original = ans;
        // }

        // return ans;

        while(st.count(original)) original *= 2;
        return original;
    }
};
