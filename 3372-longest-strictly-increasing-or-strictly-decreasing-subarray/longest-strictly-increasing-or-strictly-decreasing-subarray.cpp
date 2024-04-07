class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        for(int i=1; i<n; i++){
            int c = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[j+1] > nums[j]){
                    c++;
                }else{
                    break;
                }
            }
            maxi = max(maxi, c);
        }
        for(int i=1; i<n; i++){
            int c = 1;
            for(int j=i-1; j>=0; j--){
                if(nums[j+1] < nums[j]){
                    c++;
                }else{
                    break;
                }
            }
            maxi = max(maxi, c);
        }
        return maxi;
    }
};