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
    int solve(TreeNode* root, int num){
        if(root == NULL)  return 0;

        num = num*10 + root->val;

        int left = solve(root->left, num);
        int right = solve(root->right, num);

        if(root->left == NULL and root->right == NULL) return num;
        return left + right;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root, 0);
    }
};