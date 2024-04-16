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
    void solve(TreeNode* root, int val, int depth){
        if(root == NULL){
            return;
        }

        if(depth <= 1){
            TreeNode* left = root->left, *right = root->right;

            TreeNode* temp1 = new TreeNode(val);
            TreeNode* temp2 = new TreeNode(val);

            root->left = temp1;
            root->right = temp2;

            temp1->left = left;
            temp2->right = right;
            return;
        }

        solve(root->left, val, depth-1);
        solve(root->right, val, depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root, newRoot->right = NULL;
            return newRoot;
        }
        solve(root, val, depth-1);
        return root;
    }
};