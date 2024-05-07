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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> st;

        while(curr != NULL){
            while(!st.empty() and st.top()->val < curr->val){
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }

        ListNode* next = NULL;
        while(!st.empty()){
            curr = st.top();
            st.pop();

            curr->next = next;
            next = curr;
        }
        return curr;
    }
};


/*

class Solution {

public:

    ListNode* removeNodes(ListNode* head) {

        ListNode* cur = head;

        stack<ListNode*> stack;

        

        while (cur != nullptr) {

            while (!stack.empty() && stack.top()->val < cur->val) {

                stack.pop();

            }

            stack.push(cur);

            cur = cur->next;

        }

        

        ListNode* nxt = nullptr;

        while (!stack.empty()) {

            cur = stack.top();

            stack.pop();

            cur->next = nxt;

            nxt = cur;

        }

        

        return cur;

    }

};

*/