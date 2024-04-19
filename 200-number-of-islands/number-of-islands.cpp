class Solution {
public:
    int n, m;
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == '0' or grid[i][j] == '$'){
            return;
        }
        // vis[i][j] = 1;
        grid[i][j] = '$';
        for(auto dir: directions){
            int nrow = i + dir[0];
            int ncol = j + dir[1];

            dfs(nrow, ncol, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int cnt= 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;  
    }
};