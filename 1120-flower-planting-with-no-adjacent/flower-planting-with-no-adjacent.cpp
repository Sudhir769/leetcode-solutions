class Solution {
public:
    vector<int> ans;
    int newColor;
    void solve(int flower, int color, unordered_map<int, vector<int>> &adj){

        ans[flower] = color;
        newColor = color+1 == 5 ? 1:color+1;

        for(auto neigh: adj[flower]){
            if(ans[neigh] == 0){
                solve(neigh, newColor, adj);
            }else if(ans[flower] == ans[neigh]){
                solve(flower, newColor, adj);
            }
        }
        return;
        
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int, vector<int>> adj;
        ans.resize(n, 0);

        for(auto path:paths){
            int u = path[0] - 1;
            int v = path[1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<n; i++){
            if(ans[i] == 0){
                solve(i, 1, adj);
            }
        }
        return ans;
    }
};