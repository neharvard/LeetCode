/*
    Leetcode Link               : https://leetcode.com/problems/maximum-matrix-sum
*/


/******************************************** C++ ********************************************/
//Approach - Check Odd or Even count of -ves
//T.C : O(row*col)
//S.C : O(1)
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        long long sum = 0, negCnt = 0;
        int mn = INT_MAX;

        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                sum += abs(matrix[i][j]);
                
                if(matrix[i][j] < 0){
                    negCnt++;
                }

                mn = min(mn, abs(matrix[i][j])); 
            }
        }

        // cout<<"neg:"<<negCnt<<" min: "<<mn<<" sum: "<<sum<<endl;
        
        if(negCnt % 2 == 0) return sum;
        return sum - (mn * 2);
    }
};
