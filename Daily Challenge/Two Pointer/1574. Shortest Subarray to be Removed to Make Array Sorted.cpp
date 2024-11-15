/*
    Leetcode Link               : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted
*/


/************************************************************ C++ ************************************************/
//Approach (simple two pointer approach)
//T.C : O(n) - We don't visit any element once inside the while loop
//S.C : O(1)
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int sz = arr.size();
        int i = 0, j = sz - 1;

        for ( ; j > 0; j--) {
            if (arr[j] < arr[j - 1]) break;
        }

        int ans = j; 

        for ( ; i < j; i++) {
            if (i == 0 || arr[i] >= arr[i - 1]) {
                while (j < sz && arr[i] > arr[j]) j++;

                ans = min(ans, (j - i - 1));
                // cout<<"i:"<<i<<" j:"<<j<<" ans:"<<ans<<endl;
            }
            else break;
        }

        return ans;
    }
};
