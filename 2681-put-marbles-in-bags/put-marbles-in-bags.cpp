class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans=0;

        priority_queue<int> pq;
        priority_queue<int,vector<int>,greater<int>>pq1;

        for(int i=0;i<weights.size()-1;i++){
            pq.push(weights[i] + weights[i+1]);
            pq1.push(weights[i] + weights[i+1]);
        }

        int x=k-1;

        while(x--){
            ans+=pq.top();
            ans-=pq1.top();

            pq.pop();
            pq1.pop();
        }
        return ans;
    }
};