class Solution {
public:
    int bSearch(vector<int>& nums, int start, int end, int target){
        int result = 0;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(nums[mid] <= target){
                result = mid;
                start = mid+1;
            }else{
                end = mid-1;
            }
        }
        return result;
    }
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int result = 0;
        for(int i=0; i<n; i++){
            int x = nums[i];
            int y = x + 2*k;

            int j = bSearch(nums, i+1, n-1, y);
            result = max(result, j-i+1);
        }
        return result;
    }
};