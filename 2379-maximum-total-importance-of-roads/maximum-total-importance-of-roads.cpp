class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n, 0);
        long long importance = 0;
        for(auto it:roads){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(), indegree.end());
        for(long long i=1; i<=n; i++){
            importance += (long long)(i*indegree[i-1]);
        }
        return importance;
    }
};