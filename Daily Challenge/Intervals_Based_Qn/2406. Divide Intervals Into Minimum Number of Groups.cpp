/*
    Leetcode Link               : https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups
*/


/**************************************************** C++ ****************************************************/
//Approach (Simply sorting and using Min Heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>>pq;
      
        for(auto &it : intervals){
            int left = it[0], right = it[1];
            if(!pq.empty() && left > pq.top()){
                pq.pop();
            } 
            pq.push(right);
        }
        return pq.size();
    }
};


//Approach: BruteForce - give TLE
//T.C : O(N^2)
//S.C : O(N)
class Solution {
public:
   static const int N = 1e5+5;
   int vis[N];
    int minGroups(vector<vector<int>>& intervals) {
        int sz = intervals.size();
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        for(int i=0; i<intervals.size(); i++){
            if(vis[i])continue;
            int left = intervals[i][0], right = intervals[i][1];
            // cout<<"l:"<<left<<" r:"<<right<<endl;
            for(int j=i+1; j<intervals.size(); j++){ 
                if(vis[j]) continue;
                int x = intervals[j][0];  //cout<<"x:"<<x<<endl;
                if(x > right){ //cout<<"x1:"<<x<<endl;
                   right = intervals[j][1];
                   vis[j] = 1;
                }
            }
            ans++;
        }
        return ans;
    }
};
