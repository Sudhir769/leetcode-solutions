class Solution {
public:
    vector<int>dp;
    bool isPrime(int n){
        if(dp[n] != -1) return dp[n];

        if(n == 2 or n == 3 or n == 5){
            return dp[n] = 1;
        }
        if(n % 2 == 0 or n % 3 == 0 or n % 5 == 0){
            return dp[n] = 0;
        }

        for(int i=7; i*i<=n; i++){
            if(n % i == 0){
                return dp[n] = 0;
            }
        }
        return dp[n] = 1;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();

        dp.resize(101, -1);
        dp[1] = 0;

        int start = 0, end = n-1;

        int ans = INT_MIN;
        while(start <= end){
            if(!isPrime(nums[start])){
                start++;
            }else if(!isPrime(nums[end])){
                end--;
            }else{
                ans = max(ans, end-start);
                start++, end--;
            }
        }
        return ans;
    }
};