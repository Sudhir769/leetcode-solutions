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
    int cnt = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;

        while(temp){
            size++;
            temp = temp->next;
        }
        int index = size - n -1;
        if(size == 1){
            return NULL;
        }
        if(index < 0) return head->next;
        temp = head;
        while(index--){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};