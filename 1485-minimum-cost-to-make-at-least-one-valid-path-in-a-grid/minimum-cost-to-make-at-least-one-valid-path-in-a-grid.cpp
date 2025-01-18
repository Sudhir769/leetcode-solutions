class Solution {
public:
    int n, m;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        dist[0][0] = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int currCost = curr[0];
            int row = curr[1];
            int col = curr[2];

            if(dist[row][col] < currCost){
                continue;
            }

            for(int k=0; k<=3; k++){
                int nrow = row + dir[k][0];
                int ncol = col + dir[k][1];

                if(nrow >= 0 and nrow<n and ncol>=0 and ncol<m){
                    int gridDir = grid[row][col];
                    int dirCost = gridDir - 1 != k ? 1:0;

                    int newCost = currCost + dirCost;

                    if(newCost < dist[nrow][ncol]){
                        dist[nrow][ncol] = newCost;
                        pq.push({newCost, nrow, ncol});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};