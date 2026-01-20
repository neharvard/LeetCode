/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/construct-the-minimum-bitwise-array-i
*/


/******************************************************* C++ *******************************************************/
//Approach (Brute Force All Possible Answers)
//T.C : O(n * m), m = maximum number in nums
//S.C : O(1)
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(auto &it : nums){
            bool ok = false;

            for(int i=0; i<it; i++){
                int x = i | (i+1) ; 
                // cout<<"i: "<<i<<" i+1: "<<i+1<<" x: "<<x<<endl;
                if(x == it){
                    ans.push_back(i);
                    ok = true;
                    break;
                }
            }
            if(!ok) ans.push_back(-1);
        }

        return ans;
    }
};
