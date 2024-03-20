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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* temp = list1, *temp2 = list1;
        a--;
        while(a--){
            temp = temp->next;
        }
        while(b--) temp2 = temp2->next;

        temp->next = list2;
        temp = list2;
        while(temp->next) temp = temp->next;
        temp->next = temp2->next;
        return list1;
    }
};