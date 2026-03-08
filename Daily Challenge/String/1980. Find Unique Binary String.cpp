/*
      Company Tags                : Amazon, Meta, Google
      Leetcode Link               : https://leetcode.com/problems/find-unique-binary-string/
*/

/************************************************************** C++ **************************************************************/
//Approach-1 (Using simple conversion)
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int sz = nums.size();
        unordered_set<int>st;

        for(int i=0; i<sz; i++){
            st.insert(stoi(nums[i], 0, 2));
        }

        string ans;
        for(int i=0; i<=sz; i++){
            if(st.find(i) == st.end()){
                ans = bitset<16>(i).to_string();
                return ans.substr(16-sz, sz);
            }
        }

        return "";
    }
};


//Approach-2 (By discarding matching characters in each position)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int sz = nums.size();
        int n = nums[0].size();
        string ans;

        for(int i=0,j = 0; i<sz; i++){
            ans += nums[i][j] == '0' ? '1' : '0'; //cout<<"a:"<<ans<<" j:"<<j<<endl;
            j++;
        }

        return ans;
    }
};
