class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }

        while(!pq.empty()){
            int  el = pq.top()[0];
            int ind = pq.top()[1];
            pq.pop();

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