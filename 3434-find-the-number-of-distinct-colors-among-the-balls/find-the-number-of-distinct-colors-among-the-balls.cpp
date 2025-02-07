class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, 0);

        unordered_map<int, int> ballmp, colormp;

        for(int i=0; i<n; i++){
            int ball = queries[i][0];
            int color = queries[i][1];

            if(ballmp.find(ball) != ballmp.end()){
                int prev = ballmp[ball];
                colormp[prev]--;

                if(colormp[prev] == 0){
                    colormp.erase(prev);
                }
            }
            ballmp[ball] = color;
            colormp[color]++;

            ans[i] = colormp.size();
        }
        return ans;
    }
};