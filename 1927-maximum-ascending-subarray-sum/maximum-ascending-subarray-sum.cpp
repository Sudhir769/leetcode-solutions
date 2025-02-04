class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int maxSum = 0;
        int currSum = 0;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            maxSum = max(currSum, maxSum);

            if(i < n-1 and nums[i+1] <= nums[i]){
                currSum = 0;
            }
        }
        return maxSum;
    }
};