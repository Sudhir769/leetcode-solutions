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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        while(curr){
            int sum = 0;
            while(curr and curr->val != 0){
                sum += curr->val;
                curr = curr->next;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;

            curr = curr->next;
        }
        return ans->next;
    }
};