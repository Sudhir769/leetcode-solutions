class DSU{
public:
    vector<int> parent, rank;

    DSU(int n){
        parent.resize(n);
        rank.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] == x){
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            if (rank[rootA] < rank[rootB]) {
                parent[rootA] = rootB; 
                rank[rootB] += rank[rootA]; 
            } else if (rank[rootA] >= rank[rootB]) {
                parent[rootB] = rootA; 
                rank[rootA] += rank[rootB]; 
            }
        }
    }

    int getRank(int x){
        return rank[x];
    }
};


class Solution {
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DSU dsu(n*n);

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    
                    for(auto dir:directions){
                        int nrow = i + dir[0];
                        int ncol = j + dir[1];

                        if(nrow >=0 and nrow < n and ncol >= 0 and ncol < n and grid[nrow][ncol]){
                            int u = i*n + j;
                            int v = nrow*n + ncol;
                            dsu.Union(u, v);
                        }
                    }
                }
            }
        }
        int maxIsland = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    
                    unordered_set<int> st;
                    int temp = 0;
                    for(auto dir:directions){
                        int nrow = i + dir[0];
                        int ncol = j + dir[1];

                        if(nrow >=0 and nrow < n and ncol >= 0 and ncol < n and grid[nrow][ncol]){
                            int u = i*n + j;
                            int v = nrow*n + ncol;
                            
                            if(!st.count(dsu.find(v)))
                                temp += dsu.getRank(dsu.find(v));
                            
                            st.insert(dsu.find(v));
                        }
                    }
                    maxIsland = max(maxIsland, 1 + temp);
                }
            }
        }
        return maxIsland == 0 ? n*n:maxIsland;
    }
};