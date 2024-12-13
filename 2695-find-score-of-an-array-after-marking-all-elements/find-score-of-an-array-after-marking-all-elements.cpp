class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        vector<vector<int>> vec(n, vector<int> (2, 0));
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            vec[i] = {nums[i], i};
        }
        sort(vec.begin(), vec.end());

        for(int i=0; i<n; i++){
            int el = vec[i][0];
            int ind = vec[i][1];

            if(vis[ind]){
                continue;
            }
            score += el;
            vis[ind] = true;
            if(ind > 0) vis[ind-1] = true;
            if(ind < n-1) vis[ind+1] = true;
        }
        return score;
    }
};