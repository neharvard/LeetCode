/*
    Company Tags                :
    Leetcode Link               : https://leetcode.com/problems/smallest-integer-divisible-by-k/
*/



/****************************************************** C++ **************************************************************/
//Approach - Observation about Modulo(%) values
//T.C : O(k)
//S.C : O(1)
class Solution {
public:
    int smallestRepunitDivByK(int k) {
       if(k == 1) return 1;

       int num = 0;
       for(int i=1; i<=k; i++){
         num = (num * 10 + 1) % k;
         //  cout<<"num: "<<num<<endl;

         if(num == 0) return i;
       }

       return -1;
    }
};
