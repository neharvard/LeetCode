/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/avoid-flood-in-the-city/description/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary search along with map and set and greedy)
//T.C : O(n*logn)
//S.C : O(n)
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int sz = rains.size();
        unordered_map<int,int>rainyDay; // <day, idx>
        set<int>dryDay; // <zero day idx>

        vector<int>ans(sz, 1);
        for(int i = 0; i<sz; i++){
            int lake = rains[i];

            if(lake == 0) dryDay.insert(i);
            else{
                ans[i] = -1;

                // if that day already has rained and if possible to dry
                if(rainyDay.count(lake)){
                    auto it = dryDay.lower_bound(rainyDay[lake]);

                    if(it == dryDay.end()) return {};
                    
                    int day = *it; // idx of first zero encounter
                    // cout<<"day: "<<day<<" i:"<<i<<" lake: "<<lake<<endl;
                    ans[day] = lake;
                    dryDay.erase(it);
                }

                rainyDay[lake] = i;
            }
        }

        return ans;
    }
};
