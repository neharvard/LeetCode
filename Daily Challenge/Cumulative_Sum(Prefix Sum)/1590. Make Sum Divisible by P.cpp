/*
    Leetcode Link               : https://leetcode.com/problems/make-sum-divisible-by-p
*/


/************************************************************ C++ ************************************************/
// Approach: (Using prefix sum modulo and storing in hashmap)
//T.C : O(N) , S.C : O(N)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sz = nums.size();
        unordered_map<int, int> mp; // to store the prefix sum of mod p 
        int cur = 0, sum = 0, ans = sz;

        for(auto &it : nums){
           sum = (sum + it) % p;
        } 

        int target = sum % p;
        if(target == 0) return 0;
        
        mp[0] = -1;
        for(int i=0; i<sz; i++){
            cur = (cur + nums[i]) % p;
        
            int check = (cur - target + p) % p; // +p to avoid neg value
            if(mp.find(check) != mp.end()){
                int len = i - mp[check];
                ans = min(ans, len);
            } 
            
            mp[cur] = i;
        }

       
        return ans == sz ? -1 : ans;
    }
};
