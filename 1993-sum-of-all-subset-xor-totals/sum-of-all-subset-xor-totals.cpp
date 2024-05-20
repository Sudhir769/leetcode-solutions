class Solution {
public:
    int total = 0;
    int solve(int i, vector<int> &nums, int curXor){
        if(i < 0){
            return curXor;
        }

        int take = solve(i-1, nums, curXor^nums[i]);
        int notTake = solve(i-1, nums, curXor);

        return take + notTake;
    }

    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return solve(n-1, nums, 0);
    }
};