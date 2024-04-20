class Solution {
public:
    int n, m;
    pair<int, int>init = {0, 0};
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(int i, int j, int &r, int &c, vector<vector<int>> &land){
        if(i<0 or i>=n or j<0 or j>=m or land[i][j] != 1){
            return ;
        }
        land[i][j] = -1;
        r = max(i, r), c = max(j, c);
        for(auto dir:directions){
            int nrow = i + dir[0];
            int ncol = j + dir[1];

            dfs(nrow, ncol, r, c, land);
        }

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        n = land.size();
        m = land[0].size();
        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1){
                    int r = i, c = j;
                    dfs(i, j, r, c, land);
                    ans.push_back({i, j, r, c});
                }
            }
        }
        return ans;
    }
};