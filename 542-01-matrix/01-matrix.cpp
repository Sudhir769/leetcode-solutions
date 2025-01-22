class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<vector<int>> q;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int row = curr[0];
            int col = curr[1];
            int dis = curr[2];

            dist[row][col] = dis;
            for(auto dir:directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and mat[nrow][ncol] == 1){
                    mat[nrow][ncol] = 0;
                    dist[nrow][ncol] = dis + 1;
                    q.push({nrow, ncol, dis+1});
                }
            }
        }
        return dist;
    }
};