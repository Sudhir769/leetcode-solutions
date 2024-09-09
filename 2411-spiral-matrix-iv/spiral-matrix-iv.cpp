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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        ListNode* curr = head;
        int top = 0, down = m-1;
        int left = 0, right = n-1;

        while(top <= down and left <= right){

            for(int i=left; i<= right and curr; i++){
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            top++;

            for(int i=top; i<=down and curr; i++){
                matrix[i][right] = curr->val;
                curr = curr->next;
            }
            right--;

            for(int i=right; i>=left and curr; i--){
                matrix[down][i] = curr->val;
                curr = curr->next;
            }
            down--;

            for(int i=down; i>=top and curr; i--){
                matrix[i][left] = curr->val;
                curr = curr->next;
            }
            left++;
        }
        return matrix;
    }
};