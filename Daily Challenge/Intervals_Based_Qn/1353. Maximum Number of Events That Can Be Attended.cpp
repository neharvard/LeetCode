/*
    Company Tags                : Amazon, Google, Nutanix
    Leetcode Qn Link            : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended
*/


/************************************************************************ C++ ************************************************************/
//Approach (Using Sorting and heap and hreedily picking the ones ending earliest)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int sz = events.size();
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>>pq;
        int ans = 0, i = 0;
        int day = events[0][0]; 

        while(!pq.empty() || i<sz){
            if(pq.empty()) {
                day = events[i][0];
            }

            while(i<sz && events[i][0] == day){
                pq.push(events[i][1]); //cout<<"evn:"<<events[i][1]<<endl;
                i++;
            }
            //cout<<"day: "<<day<<endl;

            if(!pq.empty()){ //cout<<"top: "<<pq.top()<<endl;
                pq.pop();
                ans++;
            }

            day++;

            //skip those events whose endDay < day
            while(!pq.empty() && pq.top() < day){
                pq.pop();
            }
        }

        return ans;
    }
};
