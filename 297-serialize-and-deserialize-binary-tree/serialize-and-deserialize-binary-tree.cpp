/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";

        queue<TreeNode*> q;
        q.push(root);
        string ans = "";

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            if(node != NULL){
                ans += (to_string(node->val) + ',');
            }else{
                ans += "#,";
            }

            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        queue<TreeNode*> q;

        stringstream ss(data);
        string curr = "";
        getline(ss, curr, ',');

        TreeNode* root = new TreeNode(stoi(curr));
        q.push(root);

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            getline(ss, curr, ',');
            if(curr == "#"){
                node->left = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(curr));
                node->left = newNode;
                q.push(newNode);
            }

            getline(ss, curr, ',');
            if(curr == "#"){
                node->right = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(curr));
                node->right = newNode;
                q.push(newNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));