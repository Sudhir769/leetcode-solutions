class Solution {
public:
    int digitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;  
            number /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, priority_queue<int>> mp;

        int maxi = -1;
        for(int i=0; i<n; i++){
            int sum = digitSum(nums[i]);

            if(mp.find(sum) != mp.end()){
                maxi = max(maxi, mp[sum].top() + nums[i]);
            }
            mp[sum].push(nums[i]);
        }
        return maxi;
    }
};