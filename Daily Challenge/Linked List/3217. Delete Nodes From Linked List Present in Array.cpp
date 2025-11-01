/*
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
*/


/********************************************************************* C++ ************************************************************/
//Approach (Using Simple straight forward approach)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto &it : nums) st.insert(it);

        while(head->next != nullptr && st.find(head->val) != st.end()){
            ListNode* temp = head;
            head = head->next;
            // delete(temp); // deleting hanging Node
        }

        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            if(st.find(curr->next->val) != st.end()){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            }
            else curr = curr->next;
        }

        return head;
    }
};
