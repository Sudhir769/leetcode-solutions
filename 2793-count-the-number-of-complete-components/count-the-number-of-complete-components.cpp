class DSU{
public:
    vector<int> parent, size;
    DSU(int n){
        parent.resize(n);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    void Union(int x, int y){
        int xPar = find(x);
        int yPar = find(y);

        if(xPar == yPar) return;

        if(size[xPar] >= size[yPar]){
            parent[yPar] = xPar;
            size[xPar] += size[yPar]; 
        }else{
            parent[xPar] = yPar;
            size[yPar] += size[xPar];
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int, int> mp;

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            dsu.Union(u, v);
        }

        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];

            int root = dsu.find(u);
            mp[root]++;
        }
        int result = 0;
        for(int i=0; i<n; i++){
            if(dsu.find(i) == i){
                int v = dsu.size[i];
                int e = mp[i];

                if((v * (v-1))/2 == e){
                    result++;
                } 
            }
        }
        return result;
    }
};