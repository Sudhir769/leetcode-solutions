/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, bool> vis;
    vector<int> ans;
    void inorder(TreeNode* root){
        if(root == NULL) return;

        if(root->left)  parent[root->left] = root;
        if(root->right) parent[root->right] = root;

        inorder(root->left);
        inorder(root->right);
    }

    void dfs(TreeNode* root, int k){
        if(root == NULL or vis[root]) return;
        vis[root] = true;

        if(k == 0) ans.push_back(root->val);

        if(root->left) dfs(root->left, k-1);
        if(root->right) dfs(root->right, k-1);
        if(parent[root]) dfs(parent[root], k-1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parent[root] = NULL;
        inorder(root);

        dfs(target, k);
        return ans;
    }
};