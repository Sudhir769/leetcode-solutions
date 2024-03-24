class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        unordered_map<long long, long long>mp;
        vector<long long>ans(n, 0);
        priority_queue<pair<long long, long long>>pq;

        for(int i=0; i<n; i++){
            int id = nums[i];
            int fr = freq[i];

            mp[id] += fr;

            pq.push({mp[id], id});

            while(mp[pq.top().second] != pq.top().first){
                pq.pop();
            }

            ans[i] = pq.top().first;
        }
        return ans;
    }
};