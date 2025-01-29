class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<n+1; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int xParent = find(x);
        int yParent = find(y);

        if(rank[xParent] >= rank[yParent]){
            parent[yParent] = xParent;
            rank[xParent]++;
        }else{
            parent[xParent] = yParent;
            rank[yParent]++;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU dsu(n);

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(dsu.find(u) == dsu.find(v)){
                return {u, v};
            }

            dsu.Union(u, v);
        }
        return {};
    }
};