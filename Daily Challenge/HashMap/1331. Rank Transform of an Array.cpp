/*
    Leetcode Link               : https://leetcode.com/problems/rank-transform-of-an-array
*/


/************************************************************ C++ ************************************************/
// Approach-2: Using Vector of Pairs [More Efficient]
//T.C : O(N Log N) , S.C : O(N)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int sz = arr.size();
        vector<int> ans(sz);

        vector<pair<int, int>> temp;
        for (int i = 0; i < sz; i++){
            temp.push_back({arr[i], i});
        }
        sort(temp.begin(), temp.end());

        int rank = 1, f = 0, num;
        for (int i = 0; i < sz; i++) {
            // below is the Short version of the comment out code, both does same work
            if (i != 0 && temp[i].first == temp[i - 1].first) {
                ans[temp[i].second] = rank - 1;
            } else {
                ans[temp[i].second] = rank;
                rank++;
            }

            /*
              if(!f){
                num = it.first;
                ans[it.second] = cnt;
                f = 1;
              }
              else{
                if(it.first == num)  ans[it.second] = cnt;
                else{
                    cnt++;
                    ans[it.second] = cnt;
                    num = it.first;
                }
              }
            */
        }
        return ans;
    }
};


/************************************************************ C++ ************************************************/
// Approach-1: Using HashMap
//T.C : O(N) , S.C : O(N)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int sz = arr.size();        
        map<int, vector<int> > mp;

        for(int i=0; i<sz; i++){
            mp[arr[i]].push_back(i);
        }

        vector<int>ans(sz);
        int rank = 1;
        for(auto &it : mp){
            for(auto &el : it.second){
                ans[el] = rank;
            }
            rank++;
        }

        return ans;
    }
};
