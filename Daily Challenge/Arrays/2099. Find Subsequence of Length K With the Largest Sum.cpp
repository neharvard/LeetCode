/*
    Leetcode Link               : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Using sorting with indices)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int>ans;

        vector<pair<int,int>>v;
        for(int i=0; i<sz; i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end(), greater<pair<int,int>>());
        vector<pair<int,int>>idx;

        for(auto &it : v){
            // cout<<it.first<<" "<<it.second<<endl;
            idx.push_back({it.second, it.first});
            k--;

            if(k == 0) break;
        }

        sort(idx.begin(), idx.end());
        for(auto &it : idx) ans.push_back(it.second);

        return ans;
    }
};


//Approach-2 (Using nth_element for partial sort)
//T.C : Average O(n+k)
//S.C : O(1)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int sz = nums.size();
        vector<int>ans, temp;
        temp = nums;

        nth_element(temp.begin(), temp.begin()+k-1, temp.end(), greater<int>());
        // for(auto &it : temp) cout<<it<<" "; cout<<endl;

        int kthElement = temp[k-1];
        int countK = count(temp.begin(), temp.begin()+k, kthElement);
        // cout<<"count of K: "<<countK<<endl;

        for(int i=0; i<sz; i++){
            if(nums[i] > kthElement){
                ans.push_back(nums[i]);
                k--;
            }
            else if(nums[i] == kthElement && countK > 0){
                ans.push_back(nums[i]);
                countK--;
                k--;
            }

            if(k == 0) break;
        }

        return ans;
    }
};
