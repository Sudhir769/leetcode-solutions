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
    int n;
    TreeNode* solve(vector<int>& inorder, vector<int>& preorder, int &index, int start, int end){

            if(index >= n or start > end) return NULL;
            
            int element = preorder[index++];
            TreeNode* root = new TreeNode(element);

            int pos = mp[element];

            root->left = solve(inorder, preorder, index, start, pos-1);
            root->right = solve(inorder, preorder, index, pos+1, end);

            return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        n = preorder.size();
        int m = inorder.size();

        if(n != m) return NULL;

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }

        int index = 0;
        TreeNode* root = solve(inorder, preorder, index, 0, n-1);
        return root;
    }
};