class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][1] > 1 and grid[1][0] > 1){
            return -1;
        }

        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>,             
                greater<pair<int,   pair<int, int>>>> pq;

        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        vector<vector<int>> vis(m, vector<int>(n, 0));

        pq.push({0, {0, 0}});
        result[0][0] = 0;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            int time = node.first;
            int row = node.second.first;
            int col = node.second.second;


            if(row == m-1 and col == n-1){
                return result[m-1][n-1];
            }

            if(vis[row][col]){
                continue;
            }

            vis[row][col] = true;

            for(auto dir:directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow < 0 or nrow >= m or ncol < 0 or ncol >= n) continue;
                
                if(grid[nrow][ncol] <= (time+1)){
                    pq.push({time+1, {nrow, ncol}});
                    result[nrow][ncol] = time+1;
                }else if((grid[nrow][ncol] - time) % 2 == 0){
                    pq.push({grid[nrow][ncol] + 1, {nrow, ncol}});
                    result[nrow][ncol] = grid[nrow][ncol] + 1;
                }else{
                    pq.push({grid[nrow][ncol], {nrow, ncol}});
                    result[nrow][ncol] = grid[nrow][ncol];
                }
            }
        }
        return result[m-1][n-1];
    }
};