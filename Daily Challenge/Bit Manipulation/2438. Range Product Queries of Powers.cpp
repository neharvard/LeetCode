/*
    Company Tags                : Goldman Sachs OA 
    Leetcode Link               : https://leetcode.com/problems/range-product-queries-of-powers
*/


/************************************************************ C++ *****************************************************/
//Approach (Building powers array using bits information)
//T.C : O(Q), where Q = size of queries
//S.C : O(n)
class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {      
        string s;
        while(n/2){
            s.push_back(n%2 + '0');
            n /= 2;
        }
        if(n%2 != 0) s.push_back(n%2 + '0');

         vector<int>power;
         for(int i=0; i<s.size(); i++){
            int mul = (1<<i) % mod;
            if(s[i] == '1') power.push_back(mul);
         }
        //  for(auto &it : power) cout<<it<<" "; cout<<endl;
    
        int sz = queries.size();
        vector<int>ans;
      
        for(int i=0; i<sz; i++){
            int ff = queries[i][0];
            int ss = queries[i][1];
            
            long long int product = 1;
            for(int j=ff; j<=ss; j++){ 
                product = ((product%mod) * (power[j]%mod)) % mod;
            }
            // cout<<"i: "<<i<<" p: "<<product<<endl;
            ans.push_back((int)product);
        }

        return ans;
    }
};


/// More Cleaner Code with the Same Approach
//T.C : O(Q), where Q = size of queries
//S.C : O(1)
class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {      
        vector<int>power, ans;
        for(int i = 0; i<32; i++){
            // set the ith bit if ith bit is set in N
            if((n & (1<<i)) != 0) power.push_back(1<<i);
        }

        for(auto &it : queries){
            int start = it[0];
            int end = it[1];
            long product = 1;

            for(int j=start; j<=end; j++){ 
                product = ((product%mod) * (power[j]%mod))%mod;
            }

            ans.push_back(product);
        }
        return ans;
    }
};
