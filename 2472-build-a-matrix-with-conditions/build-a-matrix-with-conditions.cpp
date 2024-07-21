class Solution {
public:
    void dfs(int node, vector<int>adj[], vector<int>& vis, stack<int>& st, bool &cycle){
        vis[node] = 1;
        for(auto v:adj[node]){
            if(vis[v] == 0){
                dfs(v, adj, vis, st, cycle);
            }else if(vis[v] == 1){
                cycle = true;
                return;
            }
        }
        vis[node] = 2;
        st.push(node);
    }
    // vector<int> topoSort(vector<vector<int>>& edges, int &k){
    //     vector<int> adj[k+1];
    //     for(auto &edge:edges){
    //         adj[edge[0]].push_back(edge[1]);
    //     }

    //     vector<int> vis(k+1, 0);
    //     stack<int>st;
    //     bool cycle = false;
    //     for(int i=1; i<=k; i++){
    //         if(!vis[i]){
    //             dfs(i, adj, vis, st, cycle);
    //             if(cycle){
    //                 return {};
    //             }
    //         }
    //     }

    //     vector<int>order;
    //     while(!st.empty()){
    //         order.push_back(st.top());
    //         st.pop();
    //     }
    //     return order;
    // }

    vector<int> topoSort(vector<vector<int>>&edges, int &k){
        vector<int> adj[k+1];
        vector<int>indegree(k+1, 0);
        for(auto &edge:edges){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int>q;
        int count = 0;
        for(int i=1; i<=k; i++){
            if(indegree[i] == 0){
                q.push(i);
                count++;
            }
        }
        vector<int>topoOrder;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            topoOrder.push_back(u);

            for(int &v:adj[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        if(count != k){
            return {};
        }
        return topoOrder;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);

        if(topoRow.empty() or topoCol.empty()){
            return {};
        }

        vector<vector<int>>matrix(k, vector<int>(k, 0));
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(topoRow[i] == topoCol[j]){
                    matrix[i][j] = topoRow[i];
                }
            }
        }
        return matrix;
    }
};