class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        int Q = queries.size();
        vector<int> result(Q, 0);

        vector<pair<int, int>> sorted;
        for(int i=0; i<Q; i++){
            sorted.push_back({queries[i], i});
        }
        sort(sorted.begin(), sorted.end());
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int points = 0;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        for(int i=0; i<Q; i++){
            int val = sorted[i].first;
            int ind = sorted[i].second;
            while(!pq.empty() and pq.top()[0] < val){
                int row = pq.top()[1];
                int col = pq.top()[2];
                pq.pop();

                points++;

                for(auto dir:directions){
                    int nrow = row + dir[0];
                    int ncol = col + dir[1];

                    if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and !vis[nrow][ncol]){
                        pq.push({grid[nrow][ncol], nrow, ncol});
                        vis[nrow][ncol] = true;
                    }
                }
            }
            result[ind] = points;
        }
        return result;
    }
};