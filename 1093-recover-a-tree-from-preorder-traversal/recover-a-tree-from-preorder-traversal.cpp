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
    int n;
    TreeNode* solve(int &i, int depth, string &s){
        if(i >= n) return NULL;

        int j = i;
        while(j < n and s[j] == '-'){
            j++;
        }
        int dash = j-i;
        if(dash != depth) return NULL;

        i += dash;

        int num=0;
        while(i < n and isdigit(s[i])){
            num = (num *10) + (s[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode(num);

        root->left = solve(i,  depth + 1, s);
        root->right = solve(i, depth + 1, s);

        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.length();
        int i=0;
        int depth = 0;

        return solve(i, 0, traversal);
    }
};