class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double fraction = INT_MAX;
        priority_queue<pair<double, pair<int,int>>,
             vector<pair<double, pair<int,int>>>,
                 greater<pair<double, pair<int,int>>>>pq;
        for(int i=0; i< n; i++){
            for(int j=i+1; j< n; j++){
                fraction = static_cast<double>(arr[i]) / static_cast<double>(arr[j]);;
                pq.push({fraction, {arr[i], arr[j]}});
            }
        }
        while(k > 1){
            pq.pop();
            k--;
        }
        return {pq.top().second.first, pq.top().second.second};
    }
};