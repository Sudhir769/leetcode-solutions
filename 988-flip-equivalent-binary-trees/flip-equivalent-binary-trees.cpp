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
    bool solve(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL or root2 == NULL){
            return root1 == root2;
        }
        if(root1->val != root2->val){
            return false;
        }

        return (solve(root1->left, root2->left) and solve(root1->right, root2->right)) or
                (solve(root1->left, root2->right) and solve(root1->right, root2->left));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return solve(root1, root2);
    }
};