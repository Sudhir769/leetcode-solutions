class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans(n, 0);
        int less = 0, more = n-1;

        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans[less] = nums[i];
                less++;
            }
            if(nums[n-i-1] > pivot){
                ans[more] = nums[n-1-i];
                more--;
            }
        }
        for(int i=less; i<=more; i++){
            ans[i] = pivot;
        }
        return ans;
    }
};