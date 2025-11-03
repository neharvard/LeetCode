/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
*/

/************************************************************************ C++ ************************************************************************************/
//Approach:1 - Two pointer 
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sz = colors.size();
        int ans = 0, j = 0;
        char prev = colors[j];

        for(int i=1; i<sz; i++){
            char curr = colors[i];
            while(i<sz && prev == curr){ 
                // cout<<"i: "<<i<<" j: "<<j<<endl;
                if(neededTime[j] <= neededTime[i]){
                    ans += neededTime[j];
                    prev = curr; //cout<<"a1: "<<ans<<endl;
                    j = i;
                }
                else{
                    ans += neededTime[i]; //cout<<"a2: "<<ans<<endl;
                }
                i++;
                if(i<sz) curr = colors[i];
            }
            // cout<<"prev: "<<prev<<" curr: "<<curr<<endl;
            prev = curr; 
            j = i;
        }

        return ans;
    }
};



//Approach:2 - Greedily moving ahead
//T.C : O(n)
//S.C : O(1)
/// More Cleaner Approach
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sz = colors.size();
        int prevMax = 0, ans = 0;

        for(int i=0; i<sz; i++){
            if(i> 0 && colors[i] != colors[i-1]) prevMax = 0;
            
            int curr = neededTime[i];

            ans += min(prevMax, curr);
            prevMax = max(prevMax, curr);
        }

        return ans;
    }
};
