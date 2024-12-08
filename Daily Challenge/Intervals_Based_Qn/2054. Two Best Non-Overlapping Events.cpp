/*
    Leetcode Link               : https://leetcode.com/problems/two-best-non-overlapping-events
*/


/**************************************************** C++ ****************************************************/
//Approach-1 (Brute Force) - TLE
//T.C : O(n^2)
//S.C : O(1)
class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int endTime) {
        sort(events.begin(), events.end());
        int ans = -1;
        int sz = events.size();

        // for(int i=0; i<sz; i++) cout<<events[i][0]<<" "<<events[i][1]<<" "<<events[i][2]<<endl;

        for (int i = 0; i < sz; i++) {
            int end = events[i][1];
            int sum = events[i][2];

            for (int j = sz - 1; j >= i; j--) {
                if (end < events[j][0]) {
                    ans = max(ans, (sum + events[j][2]));
                } else
                    break;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};



//Approach-2 (Recursion + Memoization and Sorting)
//T.C : O(n * logn, After memoizing, we will visit at max n states and for binarysearch it will take log(n))
//S.C : O(n*3) ~= O(n)
class Solution {
public:
    int sz;
    int t[100001][3]; // t[events.sz][count];

    int binarySearch(vector<vector<int>>& events, int endTime) {
        int l = 0, r = sz - 1;
        int idx = sz;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (events[mid][0] > endTime) {
                idx = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return idx;
    }

    int solve(vector<vector<int>>& events, int i, int count) {
        if (count == 2 || i == sz) return 0;

        if (t[i][count] != -1) {
            return t[i][count];
        }

        int nextValidIndex = binarySearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextValidIndex, count + 1);

        int notTake = solve(events, i + 1, count);

        return t[i][count] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        memset(t, -1, sizeof(t));
        sz = events.size();
        int count = 0;

        return solve(events, 0, count);
    }
};
