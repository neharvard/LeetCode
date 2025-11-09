/* 
    Company Tags                 : 
    Leetcode Link                : https://leetcode.com/problems/count-operations-to-obtain-zero
*/


/********************************************************************* C++ *********************************************************************/
//Approach-1 (Using Maths similar to Euclidean Algorithm - Iterative)
//T.C : O(log(min(num1, num2)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 >= num2){
                ans += num1 / num2;
                num1 = num1 % num2; 
            }
            else{
                ans += num2 / num1;
                num2 = num2 % num1; 
            }
        }

        return ans;
    }
};


//Approach-2 (More Cleaner Code)
//T.C : O(log(min(num1, num2)))
//S.C : O(1)
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 != 0 && num2 != 0){
            if(num1 < num2) swap(num1, num2);
            
            ans += num1 / num2;
            num1 = num1 % num2; 
        }

        return ans;
    }
};
