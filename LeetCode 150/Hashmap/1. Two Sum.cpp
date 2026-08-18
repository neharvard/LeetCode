/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=TCaBnVIllrQ
    Company Tags                : Zoho, Flipkart, Morgan Stanley, Accolite, Amazon, Microsoft, FactSet, Hike, Adobe, Google, Wipro, SAP Labs, CarWale
    Leetcode Link               : https://leetcode.com/problems/two-sum/
*/

/******************************************************************** C++ ********************************************************************/
// Approach - 1
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        unordered_map<int, vector<int>>ump;

        for(int i=0; i<sz; i++){
            ump[nums[i]].push_back(i);
        }

        for(int i=0; i<sz; i++){
            int need = target - nums[i];

            if(ump.find(need) != ump.end()){
                // cout<<"need:"<<need<<endl;
                for(auto &el : ump[need]){
                    // cout<<el<<" ";
                    if(el != i) return {i, el};
                } 
            }
        }

        return {};
    }
};


//Approach - 2: same as one, Just More Clean Code
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sz = nums.size();
        unordered_map<int, int>ump;

        for(int i=0; i<sz; i++){
            int need = target - nums[i];

            if(ump.find(need) != ump.end()){
                return {i, ump[need]};
            }

            ump.insert({nums[i], i});
        }
      
        return {};
    }
};
