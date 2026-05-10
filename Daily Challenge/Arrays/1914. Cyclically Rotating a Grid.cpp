/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/cyclically-rotating-a-grid
*/


/************************************************** C++ **************************************************/
//Approach - Straight forward iterate layer by layer, rotate and put
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        int layer = min(row/2, col/2); 

        vector<vector<int>>ans(row,vector<int>(col));
        
        int topRow = 0, bottomRow = row-1, leftCol = 0, rightCol = col-1;
        for(int l=0; l<layer; l++){
            vector<int>temp;
            // topRow
            for(int c=leftCol; c<rightCol; c++){
                temp.push_back(grid[topRow][c]); 
            }
            // rightCol
            for(int r=topRow; r<bottomRow; r++){
                temp.push_back(grid[r][rightCol]); 
            }
            // bottomRow
            for(int c=rightCol; c>leftCol; c--){
                temp.push_back(grid[bottomRow][c]); 
            }
            // leftCol
            for(int r=bottomRow; r>topRow; r--){
                temp.push_back(grid[r][leftCol]); 
            }
            
            int sz = temp.size(); 
            int limit = k % sz; 
            // cout<<"sz: "<<sz<<" l: "<<limit<<endl;
            rotate(begin(temp), begin(temp)+limit, end(temp));

            // for(int i=0; i<temp.size(); i++)cout<<temp[i]<<" "; cout<<endl;
            int idx = 0;

             // topRow
            for(int c=leftCol; c<rightCol; c++){
                ans[topRow][c] = temp[idx]; 
                idx++;
            } 

            // rightCol
            for(int r=topRow; r<bottomRow; r++){
                ans[r][rightCol] = temp[idx]; 
                idx++;
            } 

            // bottomRow
            for(int c=rightCol; c>leftCol; c--){
                ans[bottomRow][c] = temp[idx]; 
                idx++; 
            } 

            // leftCol
            for(int r=bottomRow; r>topRow; r--){ 
                ans[r][leftCol] = temp[idx]; 
                idx++;
            }

            leftCol++, rightCol--, topRow++, bottomRow--;

        }

        return ans;
    }
};
