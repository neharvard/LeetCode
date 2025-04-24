/*
    Leetcode Link               : https://leetcode.com/problems/count-complete-subarrays-in-an-array/
*/

/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int sz = nums.size();
        set<int>st;
        for(auto &it : nums) st.insert(it);
        int uniqueSz = st.size();
        // cout<<"uq: "<<uniqueSz<<endl;

        unordered_map<int, int>ump;
        int umpSz = 0, ans = 0;

        for(int i=0,j=0; j<sz; j++){
            if(ump[nums[j]] == 0) {
                umpSz++;
            }
            ump[nums[j]]++;
                    
            while(umpSz == uniqueSz && i<sz){
                ans += (sz - j);  //cout<<"j: "<<j<<" i: "<<i<<endl;
                ump[nums[i]]--;  //cout<<"num: "<<ump[nums[i]]<<endl;
                if(ump[nums[i]] == 0) umpSz--;
                // cout<<"ump: "<<umpSz<<endl;
                i++;
            }
        }

        return ans;
    }
};
