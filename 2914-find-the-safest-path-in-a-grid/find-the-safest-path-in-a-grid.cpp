class Solution {
public:
    vector<vector<int>>directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n;
    bool check(vector<vector<int>>& dist, int sf){
        queue<pair<int, int>>q;
        vector<vector<int>>vis(n, vector<int>(n, false));
        q.push({0, 0});
        vis[0][0] = 1;

        if(dist[0][0] < sf){
            return false;
        }

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if(row == n-1 and col == n-1){
                return true;
            }

            for(auto &dir: directions){
                int nrow = row + dir[0];
                int ncol = col + dir[1];

                if(nrow >= 0 and nrow < n and ncol >= 0 and ncol < n and vis[nrow][ncol] != true){
                    if(dist[nrow][ncol] < sf){
                        continue;
                    }
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, -1));
        vector<vector<int>>vis(n, vector<int>(n, false));

        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                dist[row][col] = level;

                for(auto& dir:directions){
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];

                    if(nrow < 0 or nrow >= n or ncol < 0 or ncol >=n or vis[nrow][ncol]){
                        continue;
                    }
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
            level++;
        }

        int l = 0, r = 400;
        int result = 0;
        while(l <= r){
            int midsf = l + (r-l)/2;

            if(check(dist, midsf)){
                result = midsf;
                l = midsf + 1;
            }else{
                r = midsf - 1;
            }
        }
        return result;
    }
};