/*
    Leetcode Link               : https://leetcode.com/problems/fruits-into-baskets-ii/
*/

/*************************************************** C++ ********************************************************/
//Approach-1 (Doing simply just iterating the array)
// TC: O(n^2)
// SC: O(1)
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int sz = fruits.size();
        int ans = 0;

        for(int i=0; i<sz; i++){
            int f = 0;
            for(int j=0; j<sz; j++){
                if(baskets[j] >= fruits[i]){
                    f = 1;
                    baskets[j] = 0;
                    break;
                }
            }
            if(!f) ans++;
        }

        return ans;
    }
};
