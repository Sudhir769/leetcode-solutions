class Solution {
public:
    int solve(int i, int currOr, int maxOr, vector<int> &nums){
        if(i == nums.size()){
            if(currOr == maxOr){
                return 1;
            }
            return 0;
        }
        int take = solve(i+1, currOr | nums[i], maxOr, nums);
        int notTake = solve(i+1, currOr, maxOr, nums);

        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        for(auto it:nums){
            maxOr |= it;
        }

        return solve(0, 0, maxOr, nums);
    }
}; 