/*
    Company Tags                : Goldman Sachs OA 
    Leetcode Link               : https://leetcode.com/problems/number-of-zero-filled-subarrays
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using 2 Pointer to calculate count of subarrays)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int sz = nums.size();
        long long ans = 0;

        for(int i=0, j=0; j<sz; j++){
            if(nums[j] == 0){
                i = j;
                while(j<sz && nums[j] == 0) j++;
                // cout<<"i: "<<i<<" numI: "<<nums[i]<<" j:"<<j<<" numJ:"<<nums[j];

                long long cnt = (j-i); //cout<<" cnt: "<<cnt<<endl;
                ans += ((cnt * (cnt+1)) / 2);
            }
        }
      
        return ans;
    }
};


//Approach-2 (Better and clean approach using observation)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int sz = nums.size();
        long long ans = 0, cnt = 0;

        for(int i=0; i<sz; i++){
            if(nums[i] == 0) cnt++;
            else cnt = 0;

            ans += cnt;
        }
      
        return ans;
    }
};
