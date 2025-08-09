/*
    Leetcode Link               : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
*/


/************************************************************ C++ *****************************************************/
//Approach-1 (Using bit manipulation to form the decimal number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0 ;
        while(head){
            ans = (ans<<1) | (head->val);
            head = head->next;
        }
        
        return ans;
    }
};
