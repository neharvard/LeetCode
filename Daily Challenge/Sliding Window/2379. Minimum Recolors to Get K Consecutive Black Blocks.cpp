/*
    Leetcode Link                 : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks
*/

//Approach-1 (Brute Force)
//T.C : O(n*k)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int sz = blocks.size();
        int ans = INT_MAX;
      
        for(int i=0; i<=sz-k; i++){
            int cnt = 0;
            for(int j = i; (j-i+1) <= k; j++){
                if(blocks[j] == 'W') cnt++;
            } 
            // cout<<" cnt:"<<cnt<<endl;
            ans = min(ans, cnt);
        }

        return ans;
    }
};


//Approach-2 (Sliding Window)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int sz = blocks.size();

        int i = 0, j = 0, cnt = 0, ans = INT_MAX;
        while(i < sz && j <= i){
            if(blocks[i] == 'W') cnt++;
            if((i+1) >= k){
                ans = min(ans, cnt);
                if(blocks[j] == 'W') cnt--;
                j++;
            }
            i++;
        }

        return ans;
    }
};
