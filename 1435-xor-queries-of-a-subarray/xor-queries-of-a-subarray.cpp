class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for(auto it:queries){
            int left = it[0];
            int right = it[1];

            int curr = arr[left];
            for(int i=left+1; i<=right; i++){
                curr = curr^arr[i];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};