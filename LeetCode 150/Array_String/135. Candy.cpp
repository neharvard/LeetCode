/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/candy/
*/


/*************************************************************************** C++ ******************************************************************/
//Approach-1
//T.C : O(n)
//S.C : O(n) 
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int>candies(sz, 1);
        
        for(int i=1; i<sz; i++){
            if(ratings[i] > ratings[i-1]) candies[i] = candies[i-1]+1;
        }
        // for(auto &it : candies) cout<<it<<" "; cout<<endl;

        for(int i=sz-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int ans = 0;
        for(auto &it : candies) ans += it;
   
        return ans;
    }
};
