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
    int solve(TreeNode* root, bool isLeft){
        if(root == NULL) return 0;
        if(root->left == NULL and root->right == NULL and isLeft){
            return root->val;
        }
        
        int left = solve(root->left, 1);
        int right = solve(root->right, 0);
        return left + right;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root, 0);
    }
};