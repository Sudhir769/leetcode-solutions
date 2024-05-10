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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l = 0;
        ListNode* curr = head;
        while(curr){
            l++;
            curr = curr->next;
        }

        int eachBucketNode = l/k;
        int remainderNode = l%k;

        vector<ListNode*> ans(k, NULL);
        curr = head;

        for(int i=0; i<k; i++){
            ans[i] = curr;
            
            int cnt = eachBucketNode + ((remainderNode > 0) ? 1:0);
            ListNode* prev = curr;
            while(cnt--){
                prev = curr;
                curr = curr->next;
            }
            if(prev) prev->next = NULL;
            remainderNode--;
        }
        return ans;
    }
};