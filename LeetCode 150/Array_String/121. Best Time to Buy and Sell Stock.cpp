/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (BruteForce, it gives TLE)
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        int ans = 0;

        for(int i=0; i<sz-1; i++){
            auto mx = *max_element(prices.begin()+i+1, prices.end());
            // cout<<"i: "<<prices[i]<<" mx: "<<mx<<endl;
            ans = max(ans, (mx - prices[i]));
        }

        return ans;
    }
};


//Approach-2 (in the Fly finding the smallest element & subtract it when found greater element of its)
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int sz = prices.size();
       int ans = 0;
       int mn = prices[0];

       for(int i=1; i<sz; i++){
        if(mn < prices[i]){
            ans = max(ans, prices[i] - mn);
        }
        else mn = prices[i];
       }

       return ans;
    }
};

