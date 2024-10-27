class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &matrix){
        if(i >= n or j >= m) return 0;

        if(matrix[i][j] == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int right = solve(i, j+1, matrix);
        int diag = solve(i+1, j+1, matrix);
        int down = solve(i+1, j, matrix);

        return dp[i][j] = 1 + min({right, diag, down});
    }

    int countSquares(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();

        dp.resize(n+1, vector<int>(m+1, -1));

        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 1)
                    cnt += solve(i, j, matrix);
            }
        }
        return cnt;
    }
};