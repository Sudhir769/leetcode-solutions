class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, vector<int>& nums){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        int ans = 1;
        for(int j=0; j<i; j++){
            if(nums[i] > nums[j]){
                ans = max(ans, 1 + solve(j, nums));
            }
        }
        return dp[i] =  ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n+1, -1);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, solve(i, nums));
        }
        return ans;
    }
};