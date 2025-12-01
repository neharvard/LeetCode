/*
      Company Tags                : GOOGLE
      Leetcode Link               : https://leetcode.com/problems/maximum-running-time-of-n-computers/
*/

/****************************************************************** C++ ******************************************************************/
//Approach-1 (Using Binary Search on the result minutes) . T.C. : O(m⋅logk) - m = input array length and k = range of minutes
//T.C : O(m*log(k))
//S.C : O(1)
class Solution {
public:
    bool possible(long long mid, vector<int>& batteries, int n){
        long long target = mid * n;
        // cout<<"target: "<<target<<endl;

        for(int i=0; i<batteries.size(); i++){
            target -= min((long long)batteries[i], mid); //cout<<"t1: "<<target<<endl;
            if(target <= 0) return true;
        }
        
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long mn = *min_element(begin(batteries), end(batteries));

        long long sum = 0;
        for(auto &it : batteries){
            sum += it;
        }
        // cout<<"sum: "<<sum<<" mn: "<<mn<<endl;

        long long low = mn, high = sum/n;
        long long ans = 0;
        while(low <= high){
            long long mid = low+(high-low)/2;
            // cout<<"Mid: "<<mid<<" num: "<<(mid*n)<<endl;

            if(possible(mid, batteries, n)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        return ans;
    }
};
