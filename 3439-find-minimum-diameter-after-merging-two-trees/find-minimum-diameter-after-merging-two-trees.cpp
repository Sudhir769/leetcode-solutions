class Solution {
public:
    pair<int, int> BFS(unordered_map<int, vector<int>>& adj, int source){
        unordered_map<int, bool> vis;
        
        queue<int> q;
        q.push(source);
        vis[source] = true;

        int dia = 0;
        int farNode = source;
        while(!q.empty()){
            int n = q.size();

            while(n--){
                int node = q.front();
                q.pop();

                farNode = node;
                for(auto neighbor:adj[node]){
                    if(vis[neighbor] == false){
                        vis[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            if(!q.empty()){
                dia++;
            }
        }
        return {farNode, dia};
    }

    int findDiameter(unordered_map<int, vector<int>>& adj){

        auto [farthestNode, distance] = BFS(adj, 0);

        auto [node, diameter] = BFS(adj, farthestNode);

        return diameter;
    }

    unordered_map<int, vector<int>> findAdj(vector<vector<int>>& edges){
        unordered_map<int, vector<int>> adj;

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int, vector<int>> adj1 = findAdj(edges1);
        unordered_map<int, vector<int>> adj2 = findAdj(edges2);

        int d1 = findDiameter(adj1);
        int d2 = findDiameter(adj2);

        int combined = (d1+1)/2 + (d2+1)/2 + 1;

        return max({d1, d2, combined});
    }
};