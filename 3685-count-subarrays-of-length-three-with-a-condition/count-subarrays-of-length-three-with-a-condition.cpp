class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(int i=0; i+2<n; i++){
            if(2 * (nums[i] + nums[i+2]) == nums[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
};