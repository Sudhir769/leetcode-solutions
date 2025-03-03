class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans(n, 0);
        int cntless = 0, equal = 0;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                cntless++;
            }else if(nums[i] == pivot){
                equal++;
            }
        }

        int less = 0, pi = cntless, more = cntless + equal;
        for(int i=0; i<n; i++){
            if(nums[i] < pivot){
                ans[less] = nums[i];
                less++;
            }else if(nums[i] == pivot){
                ans[pi] = nums[i];
                pi++;
            }else{
                ans[more] = nums[i];
                more++;
            }
        }
        return ans;
    }
};