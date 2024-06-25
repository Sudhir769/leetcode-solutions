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
    vector<int>v;

    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            v.push_back(root->val);
            dfs(root->right);
        }
    }
    void dfs2(TreeNode* root, int &size){
        if(root){
            dfs2(root->left, size);
            root->val = v[size++];
            dfs2(root->right, size);
        }
    }
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        int n = v.size();

        for(int i=n-2; i>=0; i--){
            v[i] += v[i+1];
        }
        int size = 0;
        dfs2(root, size);
        return root;
    }
};