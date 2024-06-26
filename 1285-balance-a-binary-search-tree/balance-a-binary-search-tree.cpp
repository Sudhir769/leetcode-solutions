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
    void inorder(TreeNode* root, vector<int>& vec){
        if(root){
            inorder(root->left, vec);
            vec.push_back(root->val);
            inorder(root->right, vec);
        }
    }

    TreeNode* build(int l, int r, vector<int>& vec){
        if(l > r){
            return NULL;
        }
        int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = build(l, mid-1, vec);
        root->right = build(mid+1, r, vec);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        inorder(root, vec);

        int l=0, r=vec.size()-1;
        return build(l, r, vec);
    }
};