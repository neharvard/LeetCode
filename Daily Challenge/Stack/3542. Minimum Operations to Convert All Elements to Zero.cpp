/*
    MY YOUTUBE VIDEO ON THIS Qn   : 
    Company Tags                  : Will update later
    Leetcode Link                 : https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Brute Force) [ This gives TLE ]
//T.C : O(n*u), u = unique elements, in worst case  u = n
//S.C : O(u), in worst case u = n
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> st(begin(nums), end(nums)); //O(n) space

        int n = nums.size();

        int ops = 0;

        for(int target : st) { //O(U*n)
            if(target == 0)
                continue;
            
            bool flow = false;
            for(int i = 0; i < n; i++) {
                if(nums[i] == target) {
                    if(!flow) {
                        flow = true;
                        ops++;
                    }
                } else if(nums[i] < target) {
                    flow = false;
                }
            }
        }

        return ops;        
    }
};




//Approach (Optimal using Monotonic Increasing Stack)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;

        stack<int>st;
        for(int i=0; i<sz; i++){
            while(!st.empty() && st.top() > nums[i]){
                st.pop();
            }
            if(nums[i] == 0) continue;

            if(st.empty() || st.top() < nums[i]){
                ans++;
                st.push(nums[i]);
            }
        }

        return ans;
    }
};
