class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++){
            int val = arr[i];
            mp[val] = i;
        }
        int minIndex = INT_MAX;

        for(int row=0; row<n; row++){
            int maxIndex = INT_MIN;

            for(int col=0; col<m; col++){
                int val = mat[row][col];
                int ind = mp[val];

                maxIndex = max(maxIndex, ind);
            }
            minIndex = min(minIndex, maxIndex);
        }

        for(int col=0; col<m; col++){
            int maxIndex = INT_MIN;

            for(int row=0; row<n; row++){
                int val = mat[row][col];
                int ind = mp[val];

                maxIndex = max(maxIndex, ind);
            }
            minIndex = min(minIndex, maxIndex);
        }

        return minIndex;
    }
};