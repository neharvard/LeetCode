/*
    Leetcode Link               : https://leetcode.com/problems/rearranging-fruits/description/
*/


/********************************************************************** C++ **********************************************************************/
//Approach (Greedily swapping directly element or swapping via minimum element)
//T.C : O(n), Average time complexity of nth_element is O(n)
//S.C : O(n)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int>freq;
        for(auto &it : basket1) freq[it]++;
        for(auto &it : basket2) freq[it]--;
        
        int mn, flg=0;
        vector<int>finalRes;
        for(auto &it : freq){
            if(!flg){mn = it.first; flg = 1;}
            int cnt = abs(it.second);
            
            if(cnt%2) return -1;
            
            for(int i=1; i<=cnt/2; i++){
                finalRes.push_back(it.first);
            }
        }
        
        sort(begin(finalRes), end(finalRes));
        // cout<<"mn: "<<mn<<endl;
        // for(auto &it : finalRes)cout<<it<<" "; cout<<endl;
        
        long long ans = 0;
        for(int i=0; i<finalRes.size()/2; i++){
            ans += min(finalRes[i], mn*2);
        }
        
        return ans;
    }
};
