class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll>P;

    vector<int> dijkstra(vector<P> adj[], int src, int n){
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int>dist(n, INT_MAX);

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            ll currWt = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for(auto it:adj[currNode]){
                int nextNode = it.first;
                ll nextWt = it.second;

                if(dist[nextNode] > currWt + nextWt){
                    dist[nextNode] = currWt + nextWt;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        return dist;
    }

    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        int E = edges.size();
        vector<P> adj[n];
        for(auto &edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> fromSrc = dijkstra(adj, 0, n);
        vector<int> fromDest = dijkstra(adj, n-1, n);

        vector<bool>result(E, 0);
        for(int i=0; i<E; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            ll distFromSrc = fromSrc[u];
            ll distFromDest = fromDest[v];
            
            if(distFromSrc + w + distFromDest == fromSrc[n-1]){
                result[i] = 1;
            }

            distFromSrc = fromSrc[v];
            distFromDest = fromDest[u];
            
            if(distFromSrc + w + distFromDest == fromSrc[n-1]){
                result[i] = 1;
            }
        }
        return result;
    }
};