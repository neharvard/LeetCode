/*
    Company Tags                : Twitter, Amazon
    Leetcode Link               : https://leetcode.com/problems/binary-gap
*/


/******************************************************* C++ *******************************************************/
//Approach-1 (Simple find set bit & check max distance)
//T.C : O(nlogn) 
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
        long long prevIdx = -1, curIdx = 0;
        int ans = 0;

        while(n){
            int rem = n % 2;
            curIdx++;
            if(rem == 1){
                // cout<<"prev: "<<prevIdx<<" cur: "<<curIdx<<endl;
                if(prevIdx != -1) 
                 ans = max(ans, int(curIdx - prevIdx));
                 
                prevIdx = curIdx;
            }

            n /= 2;
        }

        return ans;
    }
};



//Approach-2 (Simple bit checking)
//T.C : ~O(32) i.e. O(1)
//S.C : O(1)
class Solution {
public:
    int binaryGap(int n) {
        int curr = 0;
        int prev = -1;

        int result = 0;

        while(n > 0) {
            if((n&1) > 0) {
                result = (prev != -1) ? max(result, curr - prev) : result;
                prev = curr;
            }

            curr++;
            n >>= 1;
        }

        return result;
    }
};
