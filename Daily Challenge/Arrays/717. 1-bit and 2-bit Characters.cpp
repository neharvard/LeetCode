/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/1-bit-and-2-bit-characters/description/
*/

/*********************************************************** C++ **************************************************/
//Approach-1 (Iterating from left to right)
//T.C : O(n) 
//S.C : O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int sz = bits.size();
        for(int i=0; i<sz-1; i++){
            if(bits[i] == 1){
                if(i+1 == sz-1) return false;
                i++;
            }
        }
        return true;
    }
};
