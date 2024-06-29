// class Solution {
// public:
//     void dfs(int node, int par, vector<int> &vis, vector<vector<int>>&parent, vector<int>adj[]){
//         vis[node] = 1;
        
//         for(auto it:adj[node]){
//             if(!vis[it]){
//                 parent[node].push_back(par);
//                 dfs(it, node, vis, parent, adj);
//             }
//         }
//     }

//     vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
//         vector<int>adj[n];
//         for(auto edge:edges){
//             adj[edge[0]].push_back(edge[1]);
//         }

//         vector<vector<int>>parent(n);

//         for(int i=0; i<n; i++){
//             vector<int>vis(n, 0);
//             dfs(i, i, vis, parent, adj);
//         }
//         for(int i=0; i<n; i++){
//             sort(parent[i].begin(), parent[i].end());
//         }
//         return parent;
//     }
// };

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res(n);
        vector<vector<int>> graph(n);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        for (int i = 0; i < n; ++i) {
            vector<bool> visit(n, false);
            dfs(graph, i, i, res, visit);
        }
        
        for (int i = 0; i < n; ++i) {
            sort(res[i].begin(), res[i].end());
        }
        
        return res;
    }

private:
    void dfs(vector<vector<int>>& graph, int parent, int curr, vector<vector<int>>& res, vector<bool>& visit) {
        visit[curr] = true;
        for (int dest : graph[curr]) {
            if (!visit[dest]) {
                res[dest].push_back(parent);
                dfs(graph, parent, dest, res, visit);
            }
        }
    }
};