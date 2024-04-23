class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<int> adj[n];
        vector<int>ind(n, 0);

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            ind[u]++, ind[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        for(int i=0; i<n; i++){
            if(ind[i] == 1){
                q.push(i);
            }
        }

        while(n > 2){
            int size = q.size();
            n -= size;

            while(size--){
                int u = q.front();
                q.pop();

                for(auto &v: adj[u]){
                    ind[v]--;
                    if(ind[v] == 1){
                        q.push(v);
                    }
                }
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};