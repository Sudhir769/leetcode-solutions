class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j){
        if(i < 0 or j < 0) return 0;
        if(i == 0 and j == 0){
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i-1, j) + solve(i, j-1);

    }
    int uniquePaths(int m, int n) {
        dp.resize(m, vector<int>(n, -1));
        return solve(m-1, n-1);

    }
};