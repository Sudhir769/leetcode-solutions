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
    int doubleUtil(ListNode* head){
        if(head == NULL){
            return 0;
        }
        int carry = doubleUtil(head->next);
        int newVal = 2*(head->val) + carry;
        head->val = newVal % 10;
        return newVal/10;
    }

    ListNode* doubleIt(ListNode* head) {

        int carry = doubleUtil(head);
        if(carry > 0){
            ListNode* newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }
        return head;
    }
};