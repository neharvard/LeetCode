/*
    Company Tags  : Bloomberg, Facebook, Google, Amazon, Adobe
    Leetcode Link : https://leetcode.com/problems/container-with-most-water/
*/

//Approach-1 (Two pointer Greedy)
// TC: O(N)
// SC: O(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sz = height.size();
        int i=0, j=sz-1;
        int ans = 0;

        while(i<j){
            int area = min(height[i],height[j]) * (j-i);
            ans = max(ans, area);
            // cout<<"area: "<<area<<" ans: "<<ans<<endl;

            if(height[i] <= height[j]) i++;
            else j--;
        }

        return ans;
    }
};
