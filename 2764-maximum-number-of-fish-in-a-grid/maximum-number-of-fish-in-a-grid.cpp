class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int row, int col, vector<vector<int>>& grid){
        vis[row][col] = true;

        int ans = 0;
        ans += grid[row][col];
        for(auto dir: directions){
            int nrow = row + dir[0];
            int ncol = col + dir[1];

            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n){
                if(!vis[nrow][ncol] and grid[nrow][ncol] != 0){
                    ans += dfs(nrow, ncol, grid);
                }
            }
        }
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vis.resize(m, vector<bool>(n, 0));
        int result = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0 and !vis[i][j]){
                    result = max(result, dfs(i, j, grid));
                }
            }
        }
        return result;
    }
};