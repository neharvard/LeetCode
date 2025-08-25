/*
    Leetcode Link               : https://leetcode.com/problems/diagonal-traverse/description/
*/

/*********************************************************** C++ **************************************************/
//Approach (Simulation)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    #define pb push_back
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int itr = (m-1)+n; cout<<"itr: "<<itr<<endl;

        vector<int>ans;
        ans.pb(mat[0][0]);

        int x = 0, y = 0, prevX = 0, prevY = 0, cnt = 0;
        for(int i=0; i<itr; i++){ 
            // cout<<"prX: "<<prevX<<" prY: "<<prevY<<endl;
            int f = 0;
            if(cnt % 2 == 0){
                if(!f){
                    if(prevY+1 < n) x = prevX, y = prevY + 1;
                    else x = prevX + 1, y = prevY;
                    f = 1;
                }
                while(x < m && y >= 0){  
                    // cout<<"x1: "<<x<<" y1: "<<y<<endl;
                    ans.pb(mat[x][y]);
                    prevX = x, prevY = y;
                    x++, y--;
                }
            }
            else{
                if(!f){
                    if(prevX+1 < m) x = prevX + 1, y = prevY;
                    else x = prevX, y = prevY + 1;
                    f = 1;
                }
                while(x >= 0 && y < n){ 
                    // cout<<"x2: "<<x<<" y2: "<<y<<endl;
                    ans.pb(mat[x][y]);
                    prevX = x, prevY = y;
                    x--, y++;
                }
            }
            cnt++;
        }

        return ans;
    }
};
