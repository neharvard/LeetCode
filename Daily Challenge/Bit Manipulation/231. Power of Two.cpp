/*
    Leetcode Link               : https://leetcode.com/problems/power-of-two
*/


/************************************************************ C++ *****************************************************/
//Approach-1 
//T.C : O(logn)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        
        while(n){ //cout<<"n: "<<n<<endl;
            if(n%2 && n!=1) return false;
            n /= 2; 
        }
      
        return true;
    }
};

//Approach-2
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 4 -> 0100, 3 -> 0011, 4 & 3 -> 0000
        return (n>0) && ((n & n-1) == 0);
    }
};


//Approach-3
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // 1<<30 means pow(2,30)
        return (n>0) && ((1 << 30) % n == 0);
    }
};
