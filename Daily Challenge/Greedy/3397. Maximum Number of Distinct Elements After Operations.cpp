/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations
*/


/********************************************************************** C++ **********************************************************************/
//Approach - Greedily sorting and checking each element
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int sz = nums.size();
        sort(begin(nums), end(nums));

        int prev, ans = 0;
        for(int i=0; i<sz; i++){
            if(i == 0){
                ans++;
                prev = nums[i] - k;
            }
            else{
                int check = nums[i] - k;
                if(prev >= check){
                    if(prev+1 <= nums[i]+k){
                        ans++;
                        prev += 1;
                    }
                }
                else{
                    ans++;
                    prev = check;
                }
            }
        }

        return ans;
    }
};
