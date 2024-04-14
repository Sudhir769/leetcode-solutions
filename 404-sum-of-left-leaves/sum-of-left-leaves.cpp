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
    int sum = 0;
    void solve(TreeNode* root, bool isLeft){
        if(root == NULL) return;

        solve(root->left, 1);

        if(root->left == NULL and root->right == NULL and isLeft){
            sum += root->val;
        }
        
        solve(root->right, 0);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, 0);
        return sum;
    }
};