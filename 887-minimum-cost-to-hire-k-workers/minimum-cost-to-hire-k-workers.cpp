class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>>workers;
        for(int i=0; i<n; i++){
            workers.push_back({(wage[i]*1.0)/quality[i], quality[i]});
        }

        sort(workers.begin(), workers.end());
        double ans = DBL_MAX, sum = 0;
        priority_queue<int>pq;

        for(auto worker:workers){
            double ratio = worker.first;
            sum += worker.second;
            pq.push(worker.second);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            if(pq.size() == k) ans = min(ans, sum*ratio);
        }
        return ans;
    }
}; 