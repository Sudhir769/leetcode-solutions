class Solution {
public:
    bool dfs(int source, int dest, vector<bool> &vis, unordered_map<int, vector<int>>adj){
        vis[source] = true;
        if(source == dest) return true;

        for(auto neigh:adj[source]){
            if(!vis[neigh]){
                if(dfs(neigh, dest, vis, adj)){
                    return true;
                }
            }
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>>adj;
        vector<int> indegree(numCourses, 0);

        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        unordered_map<int, unordered_set<int>> mp;
        while(!q.empty()){
            auto node = q.front();
            q.pop();

            for(auto neigh:adj[node]){
                mp[neigh].insert(node);
                for(auto &pre:mp[node]){
                    mp[neigh].insert(pre);
                }

                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        int Q = queries.size();
        vector<bool> result(Q, false);

        for(int i=0; i<Q; i++){
            int u = queries[i][0];
            int v = queries[i][1];

            result[i] = mp[v].contains(u);
        }
        return result;
    }
};