class Solution {
public:
    int n, m;
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        if(i<0 or i>=n or j<0 or j>=m or vis[i][j] or grid[i][j] == 0){
            return;
        }

        vis[i][j] = 1;

        dfs(i+1, j, vis, grid);
        dfs(i-1, j, vis, grid);
        dfs(i, j+1, vis, grid);
        dfs(i, j-1, vis, grid);
    }

    int numberOfIslands(vector<vector<int>> &grid){
        int islands = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 and !vis[i][j]){
                    dfs(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int isLands = numberOfIslands(grid);

        if(isLands == 0 or isLands > 1){
            return 0;
        }else{
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j] == 1){
                        grid[i][j] = 0;
                        int ils = numberOfIslands(grid);
                        if(ils >= 2 or ils == 0){
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                }
            }
        }
        return 2;
    }
};