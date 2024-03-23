/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;

        stack<ListNode*>st;
        while(curr){
            st.push(curr);
            curr = curr->next;
        }

        curr = head;
        int k = st.size()/2;
        while(k--){
            ListNode* top = st.top();
            st.pop();

            ListNode* temp = curr->next;
            curr->next =  top;
            top->next = temp;
            curr = temp;
        }
        curr->next = NULL;
    }
};