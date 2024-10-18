/*
    Leetcode Link               : https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets
*/


/************************************************************ C++ ************************************************/
//Approach-1 (Using Recursion+Backtracking to find subsets and check for all the subsets mxOR count) 
//T.C : O(2^n)
//S.C : O(2^n)
class Solution {
public:
     vector< vector<int> > subsets;
     void generate(vector<int>& v, int idx, vector<int>& nums){
        if(idx == nums.size()){
            // cout<<"enter"<<endl;
            // for(auto &it : v)cout<<it<<" ";cout<<endl;
            // cout<<"End"<<endl;
            subsets.push_back(v);
            return;
        }
 
        // if the number is exclude
        generate(v, idx+1, nums);
 
        // if the number is include
        v.push_back(nums[idx]); 
        generate(v, idx+1, nums);
        v.pop_back(); // for backtracking pop it to give it before form
        
     }
    int countMaxOrSubsets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> mp;

        vector<int> v;
        generate(v, 0, nums);
       
        for(auto &it : subsets){
            int bitOr = 0;
            for(auto &el : it){
                bitOr = bitOr | el;   
            } 
            // cout<<"or:"<<bitOr<<endl; 
            mp[bitOr]++;
            ans = max(ans, bitOr);
        }

        // cout<<"ans:"<<ans<<endl;
        ans = mp[ans];

        return ans;
    }
};


//Approach-2 (Using simple recursion to find subsets)
//T.C : O(2^n)
//S.C : O(1)
class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr) {
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return 1; //Found one subset
            return 0;
        }

        //Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr);

        //Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr);

        return takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums) {
            maxOr |= num;
        }

        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr);
    }
};



//Approach-3 (Memoizing to store subproblems result)
//T.C : O(n*maxOr)
//S.C : O(1)
class Solution {
public:
    //O(2^n)
    int countSubsets(int idx, int currOr, vector<int>& nums, int maxOr, vector<vector<int>>& t) {
        if(idx == nums.size()) {
            if(currOr == maxOr)
                return t[idx][currOr] = 1; //Found one subset
            return t[idx][currOr] = 0;
        }

        if(t[idx][currOr] != -1) {
            return t[idx][currOr];
        }

        //Take nums[idx]
        int takeCount = countSubsets(idx+1, currOr | nums[idx], nums, maxOr, t);

        //Not taken nums[idx]
        int notTakeCount = countSubsets(idx+1, currOr, nums, maxOr, t);

        return t[idx][currOr] = takeCount + notTakeCount;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(int &num : nums) {
            maxOr |= num;
        }
        int n = nums.size();

        vector<vector<int>> t(n+1, vector<int>(maxOr+1, -1));
        int currOr = 0;
        return countSubsets(0, currOr, nums, maxOr, t);
    }
};
