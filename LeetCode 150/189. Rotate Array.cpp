/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/rotate-array/description/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (BruteForce, using extra space)
// TC: O(n)
// SC: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        int n = sz - (k % sz); 
        // cout<<"n: "<<n<<endl;

        vector<int>temp;
        for(int i=n; i<sz; i++){
            temp.push_back(nums[i]);
        }

        nums.insert(nums.begin(), temp.begin(), temp.end());
        
        // for(auto &it : nums) cout<<it<<" "; cout<<endl;

        for(int i=n; i<sz; i++){
            nums.pop_back();
        }

        // for(auto &it : nums) cout<<it<<" "; cout<<endl;
    }
};


//Approach-2 (optimal solution, using Reverse technique inspite of extra space)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int sz = nums.size();
        int n = (k % sz);
        // cout<<"n: "<<n<<endl;

        int l = 0, r = sz - 1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++, r--;
        }
        // for(auto &it : nums)cout<<it<<" "; cout<<endl;

        l = 0, r = n-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++, r--;
        }

        l = n, r = sz-1;
        while(l < r){
            swap(nums[l], nums[r]);
            l++, r--;
        }

        // for(auto &it : nums) cout<<it<<" "; cout<<endl;
    }
};
