/*
    Company Tags                : Google, Amazon
    Leetcode Link               : https://leetcode.com/problems/maximum-width-ramp
*/


/********************************************************************** C++ **********************************************************************/
//Approach-1 : BruteForce - Passes 97/101 test cases
//T.C : O(n^2) in worst case
//S.C : O(1)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
       for(int i=0; i<sz; i++){
            for(int j=sz-1; j>i; j--){
                if(nums[i] <= nums[j]){
                    ans = max(ans, j-i);
                    break;
                } 
            }
        }
        
        return ans;
    }
};


//Approach-2 : Two Pointer (Making use of hint from Approach-1, storing max to the right) - ACCEPTED
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        vector<int>mxRight(sz);
        for(int i=sz-1; i>=0; i--){
            ans = max(ans, nums[i]);
            mxRight[i] = ans; 
        }
        ans = 0;
        for(int i=0,j=0; i<sz; i++){
            while(j<sz && nums[i] <= mxRight[j]){
                ans = max(ans, j-i); 
                j++;
            }
        }
        
        return ans;
    }
};
