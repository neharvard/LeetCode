/*
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
      Similar Leetcode Qn         : Maximum Profit in Job Scheduling 
*/

//Approach-1 (Using Recursion + Memo) using Linear Search for next event - T.C. - O(n⋅k⋅n)
/*
  We visit at most n*k states (size of memoization array) - O(n*k)
  At every state, we do a binary search - which takes O(logn) time
*/

//Approach-1 (Using Recursion + Memo) using Binary Search for next event - T.C. - O(n⋅k⋅log(n))
class Solution {
public:
    int sz;
    vector<vector<int>>t; // for Memoization
    vector<int>nxtEvent;

    int solve(vector<vector<int>>& events, int idx, int k){
       if(k == 0 || idx >= sz) return 0;

       if(t[idx][k] != -1) return t[idx][k];

       int skip = solve(events, idx+1, k);

       // linear Search
       int value = events[idx][2];
    //    while(j < sz){
    //     if(events[j][0] > events[idx][1]) break;
    //     j++;
    //    }
       
       int next = nxtEvent[idx];
       int take = value + solve(events, next, k-1);
       
       return t[idx][k] = max(skip, take);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sz = events.size();
        sort(begin(events), end(events));

        t.resize(sz+1, vector<int>(k+1, -1));
        nxtEvent.resize(sz);

        for(int i=0; i<sz; i++){
            // Binary Search (Built-in)
            vector<int>temp = {events[i][1]+1, 0, 0};
            nxtEvent[i] = upper_bound(events.begin()+i, events.end(), temp) - events.begin();
        }

        return solve(events, 0, k);
    }
};
