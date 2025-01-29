class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int xParent = find(x);
        int yParent = find(y);

        if(rank[xParent] >= rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent]++;
        }else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
};

class Solution {
public:
    bool dfs(int u, int v, unordered_map<int, vector<int>>& adj, vector<bool> &vis){
        vis[u] = true;

        if(u == v) return true;

        for(auto neigh:adj[u]){
            if(vis[neigh]) continue;

            if(dfs(neigh, v, adj, vis)){
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            vector<bool> vis(n+1, false);
            if(adj.find(u) != adj.end() and adj.find(v) != adj.end() and dfs(u, v, adj, vis)){
                return {u, v};
            }    
            adj[u].push_back(v);        
            adj[v].push_back(u);        
        }
        return {};
    }
};