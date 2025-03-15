class Solution {
public:
    bool isPossible(int mid, vector<int>& nums, int k, int n){
        int houses = 0;
        for(int i=0; i<n; i++){
            if(nums[i] <= mid){
                houses++;
                i++;
            }
        }
        return houses >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n = nums.size();

        int left, right;
        for(auto num:nums){
            left = min(left, num);
            right = max(right, num);
        }

        int result = 0;
        while(left <= right){
            int mid = (left + right)/2;

            if(isPossible(mid, nums, k, n)){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
};