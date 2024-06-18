class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size(), m = worker.size();
        int maxEl = *max_element(difficulty.begin(), difficulty.end());
        vector<int>dp(maxEl+1, 0);
        for(int i=0; i<n; i++){
            dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);
        }
        for(int i=1; i<=maxEl; i++){
            dp[i] = max(dp[i], dp[i-1]);
        }

        int profitSum = 0;
        for(int i=0; i<m; i++){
            if(worker[i] <= maxEl){
                profitSum += dp[worker[i]];
            }else{
                profitSum += dp[maxEl];
            }
        }
        return profitSum;
    }
};