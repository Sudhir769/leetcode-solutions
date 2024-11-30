class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        for(auto pair:pairs){
            int u = pair[0];
            int v = pair[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        int startNode = pairs[0][0];
        for(auto it: adj){
            int node = it.first;
            if(outdegree[node] - indegree[node] == 1){
                startNode = node;
                break;
            }
        }

        stack<int> st;
        st.push(startNode);

        vector<int> path;

        while(!st.empty()){
            int node = st.top();

            if(!adj[node].empty()){
                int neigh = adj[node].back();
                adj[node].pop_back();
                st.push(neigh);
            }else{
                path.push_back(node);
                st.pop();
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> result;
        for(int i=0; i<path.size()-1; i++){
            result.push_back({path[i], path[i+1]});
        }
        return result;
    }
};