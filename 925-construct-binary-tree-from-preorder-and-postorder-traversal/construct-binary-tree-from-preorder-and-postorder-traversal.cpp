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
    TreeNode* solve(int prestart, int preend, int poststart, vector<int>& preorder, int n){
        if(prestart > preend) return NULL;

        TreeNode* root = new TreeNode(preorder[prestart]);
        if(prestart == preend) return root;

        int nextNode = preorder[prestart+1];
        int j = mp[nextNode];

        int num = j - poststart + 1;

        root->left =  solve(prestart+1, prestart+num, poststart, preorder, n);
        root->right = solve(prestart+num+1, preend, j+1, preorder, n);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = postorder.size();
        for(int i=0; i<n; i++){
            mp[postorder[i]] = i; 
        }

        return solve(0, n-1, 0, preorder, n);
    }
};