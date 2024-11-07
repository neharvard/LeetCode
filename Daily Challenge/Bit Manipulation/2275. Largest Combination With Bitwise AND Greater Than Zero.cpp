/*
    Leetcode Link               : https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero
*/

/******************************************************** C++ ********************************************************/
//Approach-1 (Using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(24) ~= O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int count[32] = {0}, ans = 0;

        for(int bitPos=0; bitPos<32; bitPos++){ //cout<<"bit:"<<bitPos<<endl;
            for(auto &num : candidates){ 
                 // cout<<"num:"<<num<<" x:"<<(1<<bitPos)<<" y:"<<(num & (1<<bitPos))<<endl;
                if((num & (1 << bitPos)) != 0) count[bitPos]++;
            }
            ans = max(ans, count[bitPos]);
        }

        return ans;
    }
};


//Approach-2 (without using counter array)
//T.C : O(24*n) ~= O(n)
//S.C : O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;

        for(int i=0; i<32; i++){
            int count = 0;
            for(auto &num : candidates){
                if((num & (1 << i)) != 0) count++;
            }
            ans = max(ans, count);
        }

        return ans;
    }
};
