class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> leftMax(n, 0), rightMax(n, 0);
        long long result = 0;

        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], nums[i-1]);
        }
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], nums[i+1]);
        }

        for(int i=1; i<n; i++){
            result = max(result, (long long)(leftMax[i] - nums[i]) * rightMax[i]);
        }
        return result;
    }
};