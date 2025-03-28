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
    int cnt = 0;
    int solve(TreeNode* root, int k){
        if(root == NULL) return -1;


        int left = solve(root->left, k);
        cnt++;
        if(cnt == k) return root->val;
        int right = solve(root->right, k);

        return left != -1? left:right;
    }
    int kthSmallest(TreeNode* root, int k) {
        return solve(root, k);
        
    }
};