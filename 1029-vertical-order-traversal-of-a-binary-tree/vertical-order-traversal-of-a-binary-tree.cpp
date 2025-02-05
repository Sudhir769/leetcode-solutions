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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>>q;
        map<int, map<int, multiset<int>>> mp;

        q.push({root, {0, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();

            auto node = it.first;
            int ver = it.second.first;
            int level = it.second.second;

            mp[ver][level].insert(node->val);

            if(node->left) q.push({node->left, {ver-1, level+1}});
            if(node->right) q.push({node->right, {ver+1, level+1}});
        }

        for(auto ver:mp){
            vector<int> vertical;
            for(auto level:ver.second){
                vertical.insert(vertical.end(), level.second.begin(), level.second.end());
            }
            ans.push_back(vertical);
        }
        return ans;
    }
};