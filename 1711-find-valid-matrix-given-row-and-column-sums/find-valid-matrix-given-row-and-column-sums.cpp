class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<vector<int>> vec(n, vector<int>(m, 0));

        int i=0, j=0;
        while(i<n and j<m){
            vec[i][j] = min(rowSum[i], colSum[j]);

            rowSum[i] -= vec[i][j];
            colSum[j] -= vec[i][j];

            if(rowSum[i] == 0){
                i++;
            }
            if(colSum[j] == 0){
                j++;
            }
        }
        return vec;
    }
};