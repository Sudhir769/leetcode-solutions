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
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        if(root) root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        st.insert(0);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int value = node->val;

            if(node->left){
                node->left->val = 2 * value + 1;
                q.push(node->left);
                st.insert(node->left->val);
            }

            if(node->right){
                node->right->val = 2 * value + 2;
                q.push(node->right);
                st.insert(node->right->val);
            }
        }
    }
    
    bool find(int target) {
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */