class Solution {
public:
    bool canPartition(vector<int>& nums) {
         int n = nums.size();
        int sum = 0;
        
        for (int num : nums) sum += num;
        
        
        if (sum % 2 == 1) return false;
        sum /= 2;

        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;

        if (nums[0] <= sum) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int k = 1; k <= sum; k++) {
                bool dont = dp[i - 1][k];
                bool pick = (nums[i] <= k) ? dp[i - 1][k - nums[i]] : false;
                dp[i][k] = pick || dont;
            }
        }

        return dp[n - 1][sum];
    }
};