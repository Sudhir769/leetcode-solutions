class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> adj[500];
        for(int i=0; i<n-1; i++){
            adj[i].push_back(i+1);
        }

        vector<int> ans;
        for(auto query:queries){
            adj[query[0]].push_back(query[1]);

            vector<bool> vis(n, false);
            vis[0] = true;

            queue<int> q;
            q.push(0);
            int level = 0;

            while(!q.empty()){
            
                int size = q.size();
                while(size--){
                    int node = q.front();
                    q.pop();

                    if(node == n-1){
                        ans.push_back(level);
                        while (!q.empty()) {
                            q.pop();
                        }
                        break;
                    }

                    for(auto neigh:adj[node]){
                        if(!vis[neigh]){
                            q.push(neigh);
                            vis[neigh] = true;
                        }
                    }
                }
                level++;
            }
        }
        return ans;
    }
};