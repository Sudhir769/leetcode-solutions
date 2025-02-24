class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bob;

    bool bobDFS(int curr, int time, vector<int>& vis){
        vis[curr] = true;
        bob[curr] = time;
        if(curr == 0) return true;

        for(auto neighbour:adj[curr]){
            if(vis[neighbour]) continue;

            if(bobDFS(neighbour, time+1, vis) == true){
                return true;
            }
        }
        bob.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int b, vector<int>& amount) {
        int n = amount.size();

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

           adj[u].push_back(v); 
           adj[v].push_back(u); 
        }

        vector<int> vis(n, 0);
        bobDFS(b, 0, vis);

        queue<vector<int>> q;
        q.push({0, 0, 0});

        int maxVal = INT_MIN;
        int currVal = 0;
        vis.assign(n, 0);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();

            int node = curr[0];
            int time = curr[1];
            int val = curr[2];

            vis[node] = true;

            if(bob.find(node) == bob.end() or bob[node] > time){
                val += amount[node];
            }else if(bob[node] == time){
                val += (amount[node]/2);
            }

            if(adj[node].size() == 1 and node != 0){
                maxVal = max(maxVal, val);
            }

            for(auto neighbour:adj[node]){
                if(vis[neighbour]) continue;

                q.push({neighbour, time+1, val});
            }
        }  
        return maxVal;  
    }
};