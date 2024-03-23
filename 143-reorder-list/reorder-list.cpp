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
    ListNode* rev(ListNode* head){
        if(head == NULL or head->next == NULL){
            return head;
        }

        ListNode* last = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    void reorderList(ListNode* head) {

        ListNode* slow = head, *fast = head;

        while(fast and fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* reverse = rev(slow);

        ListNode* curr = head;
        while(reverse->next != NULL){
            ListNode* temp = curr->next;
            curr->next = reverse;

            ListNode* revPrev = reverse->next;
            reverse->next = temp;

            curr = temp;
            reverse = revPrev;
        }
    }
};