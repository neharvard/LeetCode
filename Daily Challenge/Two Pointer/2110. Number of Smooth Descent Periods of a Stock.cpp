/*
    Leetcode Link               : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted
*/


/************************************************************ C++ ************************************************/
//Approach (simple two pointer approach)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int sz = prices.size();
        long long ans = sz;

        for(int i = 0, j = 0; j<sz; j++){
            while(j<sz-1 && (prices[j]-prices[j+1]) == 1){
                // cout<<"p1: "<<prices[j]<<" p2: "<<prices[j+1]<<endl;
                j++;
            }
            // cout<<"i: "<<i<<" j: "<<j<<endl;
            
            long long cnt = (j-i)+1;
            ans += (cnt * (cnt-1))/2;
            if(j<sz-1) i = j+1;
        }

        return ans;
    }
};
