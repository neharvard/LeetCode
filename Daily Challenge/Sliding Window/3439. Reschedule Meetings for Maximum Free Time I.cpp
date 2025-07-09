/*
    Leetcode Link               : https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i
*/


/********************************************************************** C++ **********************************************************************/
//Approach  (Sliding Window)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int sz = startTime.size();
        vector<int>interval;
        
        int diff;
        interval.push_back(startTime[0]);
        for(int i=0; i<sz-1; i++){
            diff = startTime[i+1] - endTime[i];
            interval.push_back(diff);
        }
        diff = eventTime - endTime[sz-1];
        interval.push_back(diff);
        
        // for(auto &it : interval) cout<<it<<" "; cout<<endl;

        /// Sliding Window
        int sum = 0, ans = 0;
        sz = interval.size();
        for(int i=0,j=0; j<sz; j++){
            sum += interval[j]; 
            if((j-i) == k){
                ans = max(ans, sum);
                sum -= interval[i];
                i++;
            }
        }

        return ans;
    }
};
