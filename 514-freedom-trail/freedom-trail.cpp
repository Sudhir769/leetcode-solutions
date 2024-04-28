class Solution {
public:
    int countSteps(int ringIndex, int i, int n){
        int dist = abs(i - ringIndex);
        int wrap = n - dist;
        return min(dist, wrap);
    }

    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> mp;
        int n = ring.length();
        int m = key.length();

        for(int i=0; i<n; i++){
            char ch = ring[i];
            mp[ch].push_back(i);
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
        pq.push({0, 0, 0}); // {steps, ri, ki}
        set<pair<int, int>>vis;
        int totalSteps = 0;

        while(!pq.empty()){
            auto vec = pq.top();
            pq.pop();

            totalSteps = vec[0];
            int ri = vec[1];
            int ki = vec[2];
            char currChar = key[ki];

            if(ki >= m){
                break;
            }
            if(vis.count({ri, ki})){
                continue;
            }
            vis.insert({ri, ki});

            for(auto nextIndex: mp[currChar]){
                int steps = countSteps(ri, nextIndex, n) + totalSteps;
                pq.push({steps, nextIndex, ki+1});
            }
        }
        return totalSteps + m;
    }
};