class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int currOr, int maxOr, vector<int> &nums){
        if(i == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }
        if(dp[i][currOr] != -1){
            return dp[i][currOr];
        }

        int take = solve(i+1, currOr | nums[i], maxOr, nums);
        int notTake = solve(i+1, currOr, maxOr, nums);

        return dp[i][currOr] = take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        int maxOr = 0;
        for(auto it:nums){
            maxOr |= it;
        }
        dp.resize(n+1, vector<int>(maxOr+1, -1));
        return solve(0, 0, maxOr, nums);
    }
}; 