/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int flag = 0;

        while(!q.empty()){
            int level = q.size();
            long long currSum = 0;

            flag++;

            while(level--){
                TreeNode* node = q.front();
                q.pop();

                currSum += (long long)node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            pq.push(currSum);
            if(pq.size() > k){
                pq.pop();
            }
        }
        if(flag < k){
            return -1;
        }
        return pq.top();
    }
};