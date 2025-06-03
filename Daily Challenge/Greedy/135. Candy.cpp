/*
    Company Tags                : Amazon
    Leetcode Link               : https://leetcode.com/problems/candy/
*/


/*************************************************************************** C++ ******************************************************************/
//Approach-1
//T.C : O(n)
//S.C : O(N) ~ my first approach bt code looks messy
class Solution {
public:
    int candy(vector<int>& ratings) {
        int sz = ratings.size();
        vector<int>vec(sz,1);

        for(int i=0; i<sz-1; i++){
            if(ratings[i] > ratings[i+1]){
               if(vec[i] <= vec[i+1]) vec[i] = vec[i+1] + 1;
            } 
            else if(ratings[i] < ratings[i+1]){
                if(vec[i] >= vec[i+1]) vec[i+1] = vec[i] + 1;
            }
        }

        // for(int i=0; i<sz; i++)cout<<vec[i]<<" "; cout<<endl;

        for(int i = sz-1; i>0; i--){
            if(ratings[i] > ratings[i-1]){
                if(vec[i] <= vec[i-1]) vec[i] = vec[i-1] + 1;
            } 
            else if(ratings[i] < ratings[i-1]){
                if(vec[i] >= vec[i-1]) vec[i-1] = vec[i] + 1;
            }
        }
        
        int ans = 0;
        for(int i=0; i<sz; i++){
            // cout<<vec[i]<<" ";
            ans += vec[i];
        }   
        return ans;
    }
};


//Approach-2
//T.C : O(n)
//S.C : O(n) ~ Technique is like the first approach but more cleaner code
class Solution {
public:
    int candy(vector<int>& ratings) {
       int sz = ratings.size();
       vector<int>vec(sz,1);
      
       for(int i=1; i<sz; i++){
            if(ratings[i] > ratings[i-1]){
                vec[i] = max(vec[i], vec[i-1]+1);
            }
        }

        for(int i=sz-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                vec[i] = max(vec[i], vec[i+1]+1);
            }
        }

        int ans = 0;
        for(int i=0; i<sz; i++) ans += vec[i];
     
        return ans;
    }
};


//Approach-3
//T.C : O(n)
//S.C : O(1) 
class Solution {
public:
    int candy(vector<int>& ratings) {
       int sz = ratings.size();
       int i = 1, ans = sz;
      
        while(i < sz){
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }

            int peak = 0;
            while(ratings[i] > ratings[i-1]){
                peak++;
                ans += peak;
                i++;
                if(i == sz) return ans;
            }

            int dip = 0;
            while(i<sz && ratings[i] < ratings[i-1]){
                dip++;
                ans += dip;
                i++;
            }
            ans -= min(peak, dip);
        }
     
        return ans;
    }
};
