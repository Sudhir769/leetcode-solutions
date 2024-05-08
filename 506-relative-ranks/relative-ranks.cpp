class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string>ans(n);
        priority_queue<pair<int, int>>pq;

        for(int i=0; i<n; i++){
            pq.push({score[i], i});
        }

        int k=1;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int sc = it.first;
            int ind = it.second;

            if(k == 1){
                ans[ind] = "Gold Medal";
            }else if(k == 2){
                ans[ind] = "Silver Medal";
            }else if(k == 3){
                ans[ind] = "Bronze Medal";
            }else{
                ans[ind] = to_string(k);
            }
            k++;
        }
        return ans;
    }
};