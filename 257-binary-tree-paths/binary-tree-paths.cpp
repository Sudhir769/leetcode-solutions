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
    vector<string> ans;
    void solve(TreeNode* root, string path){
        if(root == NULL) return;


        string temp = (to_string(root->val) + "->");
        if(root->left == NULL and root->right == NULL){
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        solve(root->left, path + temp);
        solve(root->right, path + temp);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};