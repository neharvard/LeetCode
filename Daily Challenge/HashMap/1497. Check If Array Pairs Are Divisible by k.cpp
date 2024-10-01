/*
    Leetcode Link               : https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k
*/


/************************************************************ C++ ************************************************/
//Approach-(simple remainder maths)
//T.C : O(n)
//S.C : O(k)
class Solution {
public:
#define pb push_back
#define ll long long int
    bool canArrange(vector<int>& arr, int k) {
        vector<int>freq(k, 0);
        for(auto &num : arr){
            // int rem = num%k; // normal way to find rem
            // int rem = abs(num%k); //it won't work for handling neg rem
            int rem = (num%k + k) % k; //for handling neg rem need to (.. + k)%k
            freq[rem]++;
        }

        if(freq[0] % 2) return false; // corner case: if all num is div by k then freq should be even

        for(int i=1; i<=k/2; i++){
           int need = k - i;
           if(freq[i] != freq[need]){
               return false;
           } 
        }

        return true;
    }
};
