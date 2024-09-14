class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxValue = 0;
        int streak = 0;
        int result = 0;

        for(int i=0; i<n; i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                result = 0;
                streak = 0;
            }

            if(nums[i] == maxValue){
                streak++;
            }else{
                streak = 0;
            }

            result = max(result, streak);
        }
        return result;
    }
};