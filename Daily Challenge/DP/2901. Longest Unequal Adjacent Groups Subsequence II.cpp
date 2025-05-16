/*
    Leetcode Link               : https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/
*/

/**************************************************************** C++ ****************************************************************/
//Approach -  Using LIS Pattern (Longest Increasing Subsequence)
//T.C : (n^2 * L), where L = max length of a string in the words
//S.C : O(n)
class Solution {
public:
#define pb push_back

    bool checkHammingDisOne(string& s1, string& s2) {
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;

            if (diff > 1) return false;
        }

        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = groups.size();
        vector<int> dp(n, 1);
        vector<int> prevIdx(n, -1);

        int longSub = 1;
        int longSubIdx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i - 1; j++) {
                if (groups[j] != groups[i] &&
                    words[j].length() == words[i].length() &&
                    checkHammingDisOne(words[i], words[j])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        prevIdx[i] = j;

                        if (longSub < dp[i]) {
                            longSub = dp[i];
                            longSubIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> ans;
        while (longSubIdx != -1) {
            ans.pb(words[longSubIdx]);
            longSubIdx = prevIdx[longSubIdx];
        }
        reverse(begin(ans), end(ans));

        return ans;
    }
};
