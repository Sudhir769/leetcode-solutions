class Solution {
public:
    bool isBipartite(int curr, unordered_map<int, vector<int>>& adj, vector<int>&colors, int color){
        colors[curr] = color;

        for(auto neigh:adj[curr]){
            if(colors[neigh] == colors[curr]){
                return false;
            }

            if(colors[neigh] == -1){
                if(isBipartite(neigh, adj, colors, !color) == false){
                    return false;
                }
            }
        }
        return true;
    }

    int bfs(int node, unordered_map<int, vector<int>>& adj, int n){
        queue<int> q;
        q.push(node);
        vector<int> vis(n, 0);
        vis[node] = true;

        int level = 0;
        while(!q.empty()){

            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();

                for(auto neigh:adj[curr]){
                    if(!vis[neigh]){
                        q.push(neigh);
                        vis[neigh] = true;
                    }
                }
            }
            level++;
        }
        return level;
    }

    int getMaxGroup(int curr, unordered_map<int, vector<int>>& adj, vector<bool> &vis, vector<int> &levels){
        int maxGroup = levels[curr];
        vis[curr] = true;

        for(auto neigh:adj[curr]){
            if(!vis[neigh])
                maxGroup = max(maxGroup, getMaxGroup(neigh, adj, vis, levels));
        }
        return maxGroup;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge:edges){
            int u = edge[0]-1;
            int v = edge[1]-1;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> colors(n, -1);
        for(int i=0; i<n; i++){
            if(colors[i] == -1){
                if(isBipartite(i, adj, colors, 1) == false){
                    return -1;
                }
            }
        }
        vector<int> levels(n, 0);
        for(int i=0; i<n; i++){
            levels[i] = bfs(i, adj, n);
        }

        vector<bool> vis(n, 0);
        int maxGroup = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                maxGroup += getMaxGroup(i, adj, vis, levels);
            }
        }

        return maxGroup;
    }
};