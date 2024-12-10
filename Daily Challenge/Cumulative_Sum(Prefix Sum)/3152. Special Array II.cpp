/*
    Leetcode Link               : https://leetcode.com/problems/special-array-ii
*/


/**************************************************** C++ ****************************************************/
//Approach-1 (Using cumulative sum)
//T.C : O(n + m)
//S.C : O(n)
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int nSz = nums.size();
        int qSz = queries.size();
        vector<int>pref(nSz, 0);
        
        for(int i=1; i<nSz; i++){
            if((nums[i]%2 && nums[i-1]%2) || (nums[i]%2 == 0 && nums[i-1]%2 == 0)){
                pref[i] = pref[i-1] + 1;
            }
            else pref[i] = pref[i-1];
        }

        vector<bool>ans(qSz, false);
        for(int i=0; i<qSz; i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(pref[end] - pref[start] == 0) ans[i] = true;
        }

        return ans;
    }
};



//Approach-2 (Initial Thought of mine, Using Map) Too complex & not efficient
//T.C : O(n + m)
//S.C : O(n)
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {

        int qSz = queries.size();
        int nSz = nums.size();
        vector<bool> ans(qSz);

        map<pair<int,int>, vector<int>>mp;
        for(int i=0; i<qSz; i++){
            mp[{queries[i][0], queries[i][1]}].push_back(i);
        }
        
        // for(auto &el : mp){
        //     pair<int, int> key = el.first;
        //     cout<<key.first<<" "<<key.second<<endl;
        //     for(auto &it : el.second) cout<<it<<" "; cout<<endl;
        // }


        int i = 0, j = 0, prev = 0;
        for(auto &el : mp){
            pair<int, int> key = el.first;

            int start = key.first;
            int end = key.second;  //cout<<"st: "<<start<<" en: "<<end<<" val: "<<val<<endl;

            if (i == 0) j = start;
            else {
                if (prev <= start) j = start;
            }

            if (i > 0 && prev > start && ans[i - 1] == false) {
                for(auto &it : el.second) ans[it] = false;
                 //cout<<"prev: "<<prev<<" start:"<<start<<endl;
                continue;
            }
            int ok = 0;
            //cout<<"j: "<<j<<endl;
            for (; j < nSz - 1; j++) {
                if (j == end) break;

                if ((nums[j] % 2 && nums[j + 1] % 2) || (nums[j] % 2 == 0 && nums[j + 1] % 2 == 0)) {
                    //cout << "n1:" << nums[j] << " n2:" << nums[j + 1] << endl;
                    ok = 1;
                    break;
                }
            }
               
            prev = end; //cout<<"prev: "<<prev<<" ok: "<<ok<<" val: "<<endl;
            if (ok){
                for(auto &it : el.second) ans[it] = false;
            } 
            else{
                for(auto &it : el.second) ans[it] = true;
            } 
        }

        return ans;
    }
};
