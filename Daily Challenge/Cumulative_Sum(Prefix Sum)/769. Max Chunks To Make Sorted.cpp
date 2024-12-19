/*
  
    Leetcode Link               : https://leetcode.com/problems/max-chunks-to-make-sorted
*/

/**************************************************************** C++ ****************************************************************/
//Approach-1 (BruteForce)
//T.C : O(N^2)
//S.C : O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, mx = INT_MIN;
        
        for(int i=0; i<n; i++){
            int mn = INT_MAX ;
            mx = max(mx, arr[i]); //cout<<"i: "<<i<<endl;

            for(int j = i+1; j<n; j++){
                mn = min(mn, arr[j]); 
            }
            // cout<<"mn: "<<mn<<" mx: "<<mx<<endl;
            if(mx < mn) ans++; // cout<<"ans:"<<ans<<endl;
        }

        return ans;
    }
};
