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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int start, int end){

            if(index < 0 or start > end) return NULL;
            
            int element = postorder[index--];
            TreeNode* root = new TreeNode(element);

            int pos = mp[element];

            root->right = solve(inorder, postorder, index, pos+1, end);
            root->left = solve(inorder, postorder, index, start, pos-1);

            return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int m = inorder.size();

        if(n != m) return NULL;

        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        n--;

        TreeNode* root = solve(inorder, postorder, n, 0, n);
        return root;
    }
};