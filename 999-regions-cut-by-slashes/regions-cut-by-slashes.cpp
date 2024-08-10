class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &matrix){
        if(i<0 or i>=matrix.size() or j<0 or j>=matrix[0].size() or matrix[i][j] == 1){
            return;
        }
        matrix[i][j] = 1;

        dfs(i+1, j, matrix);
        dfs(i-1, j, matrix);
        dfs(i, j+1, matrix);
        dfs(i, j-1, matrix);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int regions = 0;
        vector<vector<int>> matrix(n*3, vector<int>(m*3, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '/'){
                    matrix[i*3][j*3+2] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3] = 1;
                }else if(grid[i][j] == '\\'){
                    matrix[i*3][j*3] = 1;
                    matrix[i*3+1][j*3+1] = 1;
                    matrix[i*3+2][j*3+2] = 1;
                }
            }
        }

        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    dfs(i, j, matrix);
                    regions += 1;
                }
            }
        }
        return regions;
    }
};