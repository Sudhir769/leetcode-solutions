class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();

        vector<int> lis(n, 1), lds(n, 1);
        int removals = n;

        for(int i=0; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], 1 + lis[j]);
                }
            }
        }

        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j]){
                    lds[i] = max(lds[i], 1 + lds[j]);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(lis[i] > 1 and lds[i] > 1){
                removals = min(removals, n - lis[i] - lds[i] + 1);
            }
        }
        return removals;
    }
};