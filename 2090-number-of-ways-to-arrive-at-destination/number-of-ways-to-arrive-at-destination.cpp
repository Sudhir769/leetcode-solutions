class Solution {
public:
    int mod = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            int t = road[2];

            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<pair<long long, int>, 
            vector<pair<long long, int>>, 
                greater<pair<long long, int>>>pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> cnt(n, 0);
        dist[0] = 0;
        cnt[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();

            long long time = node.first;
            int curr = node.second;

            for(auto neighbor:adj[curr]){
                int adjNode = neighbor.first;
                int adjTime = neighbor.second;

                if(time + adjTime < dist[adjNode]){
                    dist[adjNode] = time + adjTime;
                    pq.push({dist[adjNode], adjNode});
                    cnt[adjNode] = cnt[curr];
                }else if(time + adjTime == dist[adjNode]){
                    cnt[adjNode] = (cnt[adjNode] + cnt[curr]) % mod;
                }
            }
        }
        return cnt[n-1];
    }
};