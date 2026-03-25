/*
    Company Tags                   : 
    Leetcode Link                  : https://leetcode.com/problems/equal-sum-grid-partition-i/description
*/


/************************************************************ C++ *****************************************************/
//Approach - 1
//T.C : O(m*n)
//S.C : O(m+n)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        long long int totalSum = 0;

        vector<long long int>rowSum(row, 0);
        vector<long long int>colSum(col, 0);

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                totalSum += grid[i][j];
            }
        }
        // cout<<"totalSum: "<<totalSum<<endl;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){ 
                rowSum[i] += grid[i][j];
            }
        }
        for(int i=0; i<col; i++){
            for(int j=0; j<row; j++){
                colSum[i] += grid[j][i];
            }
        }
        
        long long sum = 0, temp = totalSum;
        for(auto &it : rowSum){
            // cout<<it<<" "; cout<<endl;
            sum += it;
            totalSum -= it;
            if(sum == totalSum) return true;
        } 

        sum = 0, totalSum = temp;
        for(auto &it : colSum){
            // cout<<it<<" "; cout<<endl;
            sum += it;
            totalSum -= it; 
            if(sum == totalSum) return true;
        }

        return false;
    }
};



//Approach - 2 (More optimized than 1)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        long long int totalSum = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                totalSum += grid[i][j];
            }
        }
        long long int temp = totalSum, r = 0, c = 0;

        for(int i=0; i<row; i++){
            long long int rowSum = 0;
            for(int j=0; j<col; j++){ 
                rowSum += grid[i][j];
            }
            totalSum -= rowSum;
            r += rowSum;
            if(totalSum == r) return true;
        }

        totalSum = temp;
        for(int i=0; i<col; i++){
            long long colSum = 0;
            for(int j=0; j<row; j++){
                colSum += grid[j][i];
            }
             totalSum -= colSum;
             c += colSum;
             if(totalSum == c) return true;
        }
        
        return false;
    }
};
