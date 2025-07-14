/*
    Leetcode Link               : https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer
*/


/************************************************************ C++ *****************************************************/
//Approach-1: (Iterating the linkedList and then computing)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string s ;
        while(head->next != nullptr){
            // cout<<"head: "<<head->val<<endl;
            s += to_string(head->val);
            head = head->next;
        }
        s += to_string(head->val);
        // cout<<"s: "<<s<<endl;
        
        // Binary to Decimal Convertion
        int ans = 0, cnt = 0;
        int sz = s.size();
        for(int i=sz-1; i>=0; i--){
            int x = s[i] - 48; 
            ans += (x *(pow(2,cnt))); 
            cnt++;
        }

        return ans;
    }
};


//Approach-2 (Using bit manipulation to form the decimal number)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0 ;
        while(head){
            // cout<<"head: "<<head->val<<endl;
            ans = (ans<<1) | (head->val);
            head = head->next;
        }
        
        return ans;
    }
};
