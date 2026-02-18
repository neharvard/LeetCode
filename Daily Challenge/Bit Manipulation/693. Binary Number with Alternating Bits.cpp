/*
    Company Tags                : 
    Leetcode Link               : https://leetcode.com/problems/binary-number-with-alternating-bits
*/


/******************************************************* C++ *******************************************************/
//Approach-1 
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        // char ch1 = 'a';

        // while(n){
        //     int rem = n % 2;
        //     n /= 2;
        //     char ch2 = rem + '0'; //cout<<"ch1: "<<ch1<<" ch2:"<<ch2<<endl;
        //     if(ch1 == 'a') ch1 = ch2;
        //     else{
        //         if(ch1 == ch2) return false;
        //         ch1 = ch2;
        //     }
        // }
        
        int curBit = -1;
        while(n){
            if(curBit == n % 2) return false;
            curBit = n % 2;
            
            n /= 2;
        }

        return true;
    }
};
