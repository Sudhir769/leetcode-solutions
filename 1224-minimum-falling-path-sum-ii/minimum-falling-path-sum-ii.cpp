class Solution {
public:
    int n = 0;
    vector<vector<int>>dp;
    int solve(int i, int j, vector<vector<int>>& grid){
        if(i == n-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];

        int best = INT_MAX;
        for(int nc=0; nc < n; nc++){
            if(nc == j){
                continue;
            }
            best = min(best, solve(i+1, nc, grid));
        }
        return dp[i][j] = grid[i][j] + best;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int ans = INT_MAX;
        dp.resize(n+1, vector<int>(n+1, -1));

        for(int i=0; i<n; i++){
            ans = min(ans, solve(0, i, grid));
        }
        return ans;
    }
};