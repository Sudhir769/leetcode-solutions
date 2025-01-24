class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for(int i=0; i<n; i++){
            for(auto it:graph[i]){
                adj[it].push_back(i);
                indegree[i]++;
            }
        }

        vector<int> result;
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            result.push_back(node);

            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};