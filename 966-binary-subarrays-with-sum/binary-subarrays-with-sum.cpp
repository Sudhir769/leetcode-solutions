class Solution {
public:
    int solve(vector<int>& nums, int goal){
        int start = 0, end = 0, cnt = 0;
        int sum = 0;
        while(end < nums.size()){
            sum += nums[end++];
            while(sum > goal and start < end) sum -= nums[start++];
            cnt += end-start;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal-1);
    }
};