/*
    Company Tags                 : Amazon
    Leetcode Link                : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

// Approach: Two Pointer
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int sz = numbers.size();
        int i = 0, j = sz-1;

        while(i < j){
            int diff = target - numbers[i];
            // cout<<"diff:"<<diff<<endl;

            while(j > i && numbers[j] >= diff){
                // cout<<"num:"<<numbers[j]<<endl;
                if(numbers[j] == diff){
                    return {i+1, j+1};
                }
                j--;
            }
           
            i++;
        }

        return {} ;
    }
};
