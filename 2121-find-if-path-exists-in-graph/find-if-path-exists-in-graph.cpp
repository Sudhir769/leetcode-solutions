class Solution {
public:
    bool dfs(int src, int dest, vector<int> adj[], vector<int> &vis){
        vis[src] = 1;

        if(src == dest){
            return true;
        }

        for(auto it:adj[src]){
            if(vis[it] == 0){
                if(dfs(it, dest, adj, vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n, 0);
        return dfs(source, destination, adj, vis);
    }
};