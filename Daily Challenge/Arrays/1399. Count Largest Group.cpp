/*
    Leetcode Link               : https://leetcode.com/problems/count-largest-group/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Simulation)
//T.C : O(n * logn)
//S.C : O(n)
class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> freq;
        int mx = INT_MIN;

        for (int i = 1; i <= n; i++) {
            int sum = 0;
            if (i <= 9) {
                freq[i]++;
                mx = max(mx, freq[i]);
                continue;
            }
            int temp = i;
            while (temp != 0) {
                sum += temp % 10;
                temp = temp / 10;
            }
            freq[sum]++;
            mx = max(mx, freq[sum]);
        }
        // cout << "mx: " << mx << endl;
        
        int ans = 0;
        for (auto& it : freq) {
            // cout<<it.first<<" "<<it.second<<endl;
            if (it.second == mx)
                ans++;
        }

        return ans;
    }
};
