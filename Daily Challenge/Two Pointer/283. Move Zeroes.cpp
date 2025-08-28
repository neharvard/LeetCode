/*
    Company Tags                : Therap, WellDev 
    Leetcode Link               : https://leetcode.com/problems/move-zeroes
*/


/************************************************************ C++ ************************************************/
//Approach (simple two pointer approach)
//T.C : O(n) - We don't visit any element once inside the while loop
//S.C : O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sz = nums.size();
        int flg = 0, i = 0, j = 0;

        while(j<sz && i<sz){
            if(nums[i] == 0){
                flg = 1;
                while(j<sz && nums[j] == 0) j++;
                if(j == sz) break;

                swap(nums[i], nums[j]);
                i++;
            }
            
            j++;
            if(!flg)i++;
        }
    }
};
