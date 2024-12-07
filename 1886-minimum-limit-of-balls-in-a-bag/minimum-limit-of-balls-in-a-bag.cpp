class Solution {
public:
    bool isPossible(int target, int maxOperations, vector<int> &nums){
        int totalOps = 0;
        for(auto num: nums){
            int ops = num / target;
            if(num % target == 0) ops--;

            totalOps += ops;
            if(totalOps > maxOperations){
                return false;
            }
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());

        int result = right;
        while(left <= right){
            int mid = (left + right) / 2;

            if(isPossible(mid, maxOperations, nums)){
                result = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return result;
    }
};