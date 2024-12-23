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
    int minOps(vector<int>& vec){
        int swaps = 0;
        vector<int> sortedVector(vec.begin(), vec.end());

        sort(sortedVector.begin(), sortedVector.end());
        unordered_map<int, int> mp;

        for(int i=0; i<vec.size(); i++){
            mp[vec[i]] = i;
        }

        for(int i=0; i<vec.size(); i++){
            if(vec[i] == sortedVector[i]) continue;

            int currIndex = mp[sortedVector[i]];
            mp[vec[i]] = currIndex;
            mp[vec[currIndex]] = i;
            swap(vec[currIndex], vec[i]);
            swaps++;
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int result = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int> vec;

            while(n--){
                auto node = q.front();
                q.pop();

                vec.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }

            result += minOps(vec);
        }
        return result;
    }
};