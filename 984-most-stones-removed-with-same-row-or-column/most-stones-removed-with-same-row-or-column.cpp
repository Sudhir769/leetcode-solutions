// class DSU{
// public:
//     vector<int> parent, rank;
//     int n;

//     DSU(int k){
//         n = k;
//         rank.resize(k, 0);
//         parent.resize(k);
//         for(int i=0; i<k; i++) parent[i] = i;
//     }

//     int find(int i){
//         if(parent[i] != i){
//             parent[i] = find(parent[i]);
//         }
//         return parent[i];
//     }

//     void Union(int i, int j){
//         int root_i = find(i);
//         int root_j = find(j);

//         if(root_i != root_j){
//             if(rank[root_i] >= rank[root_j]){
//                 parent[root_j] = root_i;
//             }else{
//                 parent[root_j] = root_i;
//             }
//         }
//     }
// };

// class Solution {
// public:
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();
//         DSU ds(n);

//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]){
//                     ds.Union(i, j);
//                 }
//             }
//         }

//         int groups = 0;
//         for(int i=0; i<n; i++){
//             if(ds.parent[i] = i){
//                 groups++;
//             }
//         }
//         return groups;
//     }
// };

class Solution {
public:
    void dfs(int &n, int idx, vector<bool>&visited, vector<vector<int>>&stones)
    {
        visited[idx] = true;
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                if(stones[idx][0] == stones[i][0])
                    dfs(n, i, visited, stones);

                if(stones[idx][1] == stones[i][1])
                    dfs(n, i, visited, stones);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) 
    {
        int n = stones.size();
        int group = 0;

        vector<bool>visited(n);
        for(int i = 0; i<n; i++)
        {
            if(!visited[i])
            {
                dfs(n, i, visited, stones);
                group += 1;
            }
        }
        return n - group;
    }
};