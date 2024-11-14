/*
    Leetcode Link               : https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store
*/


/************************************************************ C++ ************************************************/
//Approach: Using Binary Search for checking possible value
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        sort(quantities.begin(), quantities.end());
        // for(auto &el : quantities) cout<<el<<" "; cout<<endl;

        int l = 1, r = quantities[m-1], ans = INT_MAX;
        while(l <= r){
            int mid = (l + r) / 2; //cout<<"l:"<<l<<" r:"<<r<<" mid:"<<mid<<endl;
            int need = 0;
            for(int i=0; i<m; i++){ 
                need += (quantities[i] / mid);
                if(quantities[i] % mid) need++;
            }
            // cout<<"need: "<<need<<endl;
            if(need <= n){
                ans = min(ans, mid);
                r = mid - 1;
            }
            else l = mid + 1;
        }

        return ans;
    }
};
