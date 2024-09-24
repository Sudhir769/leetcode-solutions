struct TrieNode{
    char digit;
    TrieNode* children[10];
};

class Solution {
public:

    TrieNode* getTrieNode(){
        TrieNode* node = new TrieNode();
        for(int i=0; i<=9; i++){
            node->children[i] = NULL;
        }
        return node;
    }

    void insert(int num, TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);

        for(auto ch: numStr){
            int idx = ch - '0';
            if(!crawl->children[idx])
                crawl->children[idx] = getTrieNode();
            crawl = crawl->children[idx];
        }
    }

    int search(int num, TrieNode* root){
        TrieNode* crawl = root;
        string numStr = to_string(num);
        int len = 0;

        for(auto ch:numStr){
            int idx = ch - '0';
            if(crawl->children[idx]){
                len++;
                crawl = crawl->children[idx];
            }else{
                break;
            }
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = getTrieNode();

        for(auto num:arr1){
            insert(num, root);
        }

        int result = 0;
        for(auto num: arr2){
            result = max(result, search(num, root));
        }
        return result;
    }
};