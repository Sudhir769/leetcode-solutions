class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,             
                greater<pair<int,   pair<int, int>>>> pq;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> vis(m, vector<int>(n, 0));

        pq.push({0, {0, 0}});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int wt = node.first;
            int row = node.second.first;
            int col = node.second.second;

            if(row == m-1 and col == n-1){
                return wt;
            }

            for(auto dir:directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >=0 and nrow<m and ncol >=0 and ncol<n and !vis[nrow][ncol]){
                    int nwt = wt + grid[nrow][ncol];
                    pq.push({nwt, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return -1;
    }
};