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
    bool isPalindrome(ListNode* head) {
        ListNode * curr = head, *prev = NULL, *fast = head;
        ListNode* temp;
        while(fast and fast->next){
            fast = fast->next->next;
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if(fast != NULL){
            curr = curr->next;
        }
        while(curr and prev){
            if(curr->val != prev->val){
                return false;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return true;
    }
};