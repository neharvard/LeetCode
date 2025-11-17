/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away
*/

/*********************************************************** C++ **************************************************/
//Approach - Iterate in the array and check the condition
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int sz = nums.size();
        int prevIdx = -1;
        for(int i=0; i<sz; i++){
            if(nums[i] == 1){  
                if(prevIdx == -1) prevIdx = i;
                else{
                    int diff = i - prevIdx; 
                    //cout<<"i:"<<i<<" prev:"<<prevIdx<<" diff:"<<diff<<endl;
                    if(diff <= k) return false;
                    prevIdx = i;
                }
            }
        }

        return true;
    }
};
