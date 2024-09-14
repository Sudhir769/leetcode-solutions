class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        long long x_y = 0;
        long long x2_y2 = 0;

        for(int i=0; i<n; i++){
            x_y += nums[i] - (i+1);
            x2_y2 += (nums[i] * nums[i] - (i+1) * (i+1)); 
        }

        long long x__y = x2_y2/x_y;

        int x = (x__y + x_y)/2;
        int y = (x__y - x);
        return {x, y};
    }
};