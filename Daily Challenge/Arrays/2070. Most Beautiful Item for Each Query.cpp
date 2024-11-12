/*
    Leetcode Link               : https://leetcode.com/problems/most-beautiful-item-for-each-query
*/


/************************************************************ C++ ************************************************/
//Approach-1: (using Vector pair, simple search)
//T.C : O(N logN )
//S.C : O(N)
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int sz = queries.size(), mx = 0;
        vector<int>ans(sz);

        sort(items.begin(), items.end());

        vector<pair<int, int>>vp;
        for(int i=0; i<sz; i++){
            vp.push_back({queries[i], i});
        }
        sort(vp.begin(), vp.end());
        
        for(int i=0, j = 0; i<sz; i++){
            int q = vp[i].first;
            // cout<<"q: "<<q<<endl;

            for( ; j<items.size(); j++){ 
                //cout<<"it:"<<items[j][0]<<" mx:"<<mx<<endl;
                if(items[j][0] <= q) mx = max(mx, items[j][1]);
                else break;
            }

            ans[vp[i].second] = mx;
        }

        return ans;
    }
};
