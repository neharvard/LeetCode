/*
    Company Tags          : LiveRamp
    Leetcode Link         : https://leetcode.com/problems/longest-harmonious-subsequence/
*/



/************************************************************ C++ *****************************************************/
//Approach-1: two pointer
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int sz = nums.size();
        sort(begin(nums), end(nums));

        int i = 0, j = 0, ans = INT_MIN;
        int mn = nums[i],mx, ok = 0;
      
        while(i < sz && j<=i){
            mx = nums[i]; 
            // cout<<"mx: "<<mx<<" mn:"<<mn<<" dif:"<<mx-mn<<endl;
            if(mx - mn == 1) ok = 1;
            else if(mx - mn > 1){
                if(ok) ans = max(ans, i-j);
                ok = 0;

                while(j<sz && nums[i] - nums[j] > 1){        
                    j++;
                }
                if(j < sz) mn = nums[j];
            }
            i++;
        }
        if(ok) ans = max(ans, i - j);

        return (ans == INT_MIN) ? 0 : ans;
    }
};



//Approach-2: Using map and counting
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
      
        unordered_map<int,int>freq;
        ///for(auto &it : nums) freq[it]++;

        for(int it : nums){ 
            int mn = it;
            int mx = mn + 1; 
            // cout<<"mn:"<<mn<<" mx:"<<mx<<endl;

            if(freq.find(mx) != freq.end()){
                ans = max(ans, freq[mn] + freq[mx]); 
            }
        }

        return ans;
    }
};
