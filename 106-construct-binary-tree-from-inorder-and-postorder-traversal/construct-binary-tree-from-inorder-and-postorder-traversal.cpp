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
    unordered_map<int, int> mp;
    TreeNode* solve(vector<int>& inorder, int instart, int inend, 
        vector<int>& postorder, int poststart, int postend){

            if(poststart > postend or instart > inend) return NULL;
            
            TreeNode* root = new TreeNode(postorder[postend]);

            int inroot = mp[root->val];
            int numleft = inroot - instart;

            root->left = solve(inorder, instart, inroot-1, postorder, poststart, poststart+numleft-1);
            root->right = solve(inorder, inroot+1, inend, postorder, poststart+numleft, postend-1);

            return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int m = inorder.size();

        if(n != m) return NULL;

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        TreeNode* root = solve(inorder, 0, n-1, postorder, 0, n-1);
        return root;
    }
};