class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();

        int currMinSum = nums[0];
        int minSum = nums[0];

        int currMaxSum = nums[0];
        int maxSum = nums[0];

        for(int i=1; i<n; i++){
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(currMinSum, minSum);

            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);
        }
        return max(maxSum, abs(minSum));
    }
};