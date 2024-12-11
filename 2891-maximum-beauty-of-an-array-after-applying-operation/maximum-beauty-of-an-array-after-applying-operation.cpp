class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;
        int i=0, j=0;
        while(i < n){
            while(j < n and nums[j] <= nums[i] + 2*k){
                j++;
            }
            result = max(result, j-i);
            i++;
        }
        return result;
    }
};