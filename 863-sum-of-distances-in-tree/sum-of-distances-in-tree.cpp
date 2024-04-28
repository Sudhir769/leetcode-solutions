class Solution {
public:
    long root_result = 0;
    vector<int> count;
    int N;
    int dfsBase(int curr, int prev, int depth, vector<int>adj[]){
        int total_count = 1;
        root_result += depth;

        for(auto &child: adj[curr]){
            if(child == prev){
                continue;
            }
            total_count += dfsBase(child, curr, depth+1, adj);
        }
        count[curr] = total_count;
        return total_count;
    }

    void DFS(vector<int>adj[], int parent, int prev, vector<int>& result){
        for(int &child: adj[parent]){
            if(child == prev){
                continue;
            }
            result[child] = result[parent] - count[child] + (N - count[child]);
            DFS(adj, child, parent, result);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        N=n;
        count.resize(n, 0);

        for(auto &vec: edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        root_result = 0;
        dfsBase(0, -1, 0, adj);

        vector<int>result(n, 0);
        result[0] = root_result;

        DFS(adj, 0, -1, result);
        return result;

    }
};