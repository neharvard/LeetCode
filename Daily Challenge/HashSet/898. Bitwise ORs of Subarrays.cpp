/*
    Leetcode Link               : https://leetcode.com/problems/bitwise-ors-of-subarrays/description
*/


/*************************************************************************** C++ ******************************************************************************************/
//Approach (using hashset to store previous OR values)
//T.C : O(n*32) ~ O(n)
//S.C : O(n*32) ~ O(n)
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int sz = arr.size();
        unordered_set<int>prev,curr,ans;

        for(int i=0; i<sz; i++){ /// O(n)
            for(auto &it : prev){ // O(32)
                int OR = (arr[i] | it);  /// cout<<"i: "<<arr[i]<<" OR: "<<OR<<endl;
                curr.insert(OR);
                ans.insert(OR);
            }
            curr.insert(arr[i]);
            ans.insert(arr[i]);

            prev = curr;
            curr.clear();
        }
        
        return ans.size();
    }
};
