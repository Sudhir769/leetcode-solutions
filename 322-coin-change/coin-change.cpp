class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& coins, int sum){
        if(sum == 0){
            return 0;
        }
        if(i == 0){
            if(sum % coins[i] == 0){
                return sum / coins[i];
            }
            return INT_MAX;
        }
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        int take = INT_MAX;
        if(sum >= coins[i]){
            int temp = solve(i, coins, sum-coins[i]);
            if(temp != INT_MAX){
                take = 1 + temp;
            }
        }
        int notTake = solve(i-1, coins, sum);
        
        return dp[i][sum] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        
        dp.resize(n+1, vector<int>(sum+1, -1));
        int ans = solve(n-1, coins, sum);
        if(ans != INT_MAX){
            return ans;
        }
        return -1;
    }
};