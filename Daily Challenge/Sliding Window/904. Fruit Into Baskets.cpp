/*
    Leetcode Link               : https://leetcode.com/problems/fruit-into-baskets/description/
*/


/*************************************************************** C++ *************************************************/
//Approach (Sliding Window using map)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sz = fruits.size();
        unordered_map<int,int>mp;
      
        int n = mp.size();
        int i = 0, j = 0, ans = 0;
        while(j<sz){
            if(mp[fruits[j]] == 0) n++;
            mp[fruits[j]]++;

            if(n > 2){
                ans = max(ans, j-i);
                // cout<<"i: "<<fruits[i]<<" j: "<<fruits[j]<<" ans: "<<ans<<endl;
                
                while(i<j){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0) break;
                    i++;
                }
                i++, n--;
                // cout<<"I: "<<i<<" ff: "<<fruits[i]<<endl;
            }
            j++;
        }
        // cout<<"mp: "<<n<<" i: "<<i<<" j: "<<j<<endl;
        if(n < 3) ans = max(ans, (j-i));

        return ans;
    }
};


/// More Clearner Code with the Same Approach
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int sz = fruits.size();
        unordered_map<int,int>mp;

        int i = 0, j = 0, ans = 0;
        while(j < sz){
            mp[fruits[j]]++;

            if(mp.size() <= 2) ans = max(ans, (j-i+1));
            else{
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
