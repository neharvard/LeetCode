/*
    Leetcode Link               : https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/
*/



/****************************************************************** C++ ******************************************************************/
//Approach (Binary Search and prefix sum)
//T.C : O(n+klogn)
//S.C : O(n)
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int sz = fruits.size();
        vector<int>pos(sz), pref(sz);

        pref[0] = fruits[0][1];
        for(int i=0; i<sz; i++){
            pos[i] = fruits[i][0];
            if(i != 0) pref[i] = pref[i-1] + fruits[i][1];
        }
        
        // if wanna cover left then r8 or viece versa remaining move = k - 2*d; move >= 0, 
        // k-2*d >= 0, 2d = k, d = k/2;
        int dis = k/2;  //cout<<"dis: "<<dis<<endl;

        int ans = 0, total = 0;
        for(int d=0; d<=dis; d++){
            // Case-1: move d step in the left
            int remMove = k - 2*d;
            int leftEnd = startPos - d;
            int rightEnd = startPos + remMove;

            int left = lower_bound(begin(pos), end(pos), leftEnd) - begin(pos);
            int right = upper_bound(begin(pos), end(pos), rightEnd) - begin(pos) - 1;

            if(left <= right){
                total = pref[right] - (left > 0 ? pref[left-1] : 0);
                ans = max(ans, total);
            }

            // Case-2: move d step in the right
            leftEnd = startPos - remMove;
            rightEnd = startPos + d;

            left = lower_bound(begin(pos), end(pos), leftEnd) - begin(pos);
            right = upper_bound(begin(pos), end(pos), rightEnd) - begin(pos) - 1;

            if(left <= right){
                total = pref[right] - (left > 0 ? pref[left-1] : 0);
                ans = max(ans, total);
            }
        }

        return ans;
    }
};
