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
    int widthOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){

            int mmin = q.front().second;
            int n = q.size();
            int first, last;
            for(int i=0; i<n; i++){
                auto item = q.front();
                q.pop();

                TreeNode* node = item.first;
                long long dist = item.second - mmin;

                if(i==0) first = dist;
                if(i==n-1) last = dist;

                if(node->left) q.push({node->left, 2*dist+1});
                if(node->right) q.push({node->right, 2*dist+2});
            }
            maxi = max(maxi, last - first + 1);
        }
        return maxi;
    }
};