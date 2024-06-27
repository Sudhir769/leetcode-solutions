class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int nodes = edges.size() + 1;

        vector<int> indegree(nodes+1, 0);

        for(auto it: edges){
            indegree[it[0]]++;
            indegree[it[1]]++;
        }

        return max_element(indegree.begin(), indegree.end()) - indegree.begin();
    }
};