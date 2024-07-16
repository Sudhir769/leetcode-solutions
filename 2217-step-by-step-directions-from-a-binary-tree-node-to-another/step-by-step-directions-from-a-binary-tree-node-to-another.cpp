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
    bool solve(TreeNode* root, int target, string &path){
        if(root == NULL){
            return false;
        }

        if(root->val == target){
            return true;
        }

        path.push_back('L');
        if(solve(root->left, target, path)){
            return true;
        }
        path.pop_back();
        path.push_back('R');

        if(solve(root->right, target, path)){
            return true;
        }
        path.pop_back();
        return false;


    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rts = "";
        string rtd = "";

        solve(root, startValue, rts);
        solve(root, destValue, rtd);

        int l=0;
        while(l<rts.length() and l<rtd.length() and rts[l] == rtd[l]){
            l++;
        }

        string result = "";
        for(int i=0; i<rts.length() - l; i++){
            result.push_back('U');
        }
        for(int i=l; i<rtd.length(); i++){
            result.push_back(rtd[i]);
        }

        return result;
    }
};