class Solution {
public:
    int n, m;
    vector<vector<int>>directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void dfs(int i, int j, vector<vector<int>>& grid, int &peri){
        if(i<0 or i>=n or j<0 or j>=m or grid[i][j] == 0){
            peri++;
            return;
        }
        if(grid[i][j] == -1){
            return;
        }
        grid[i][j] = -1;
        for(auto dir:directions){
            int nrow = i + dir[0];
            int ncol = j + dir[1];

            dfs(nrow, ncol, grid, peri);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int perimeter = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, perimeter);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};