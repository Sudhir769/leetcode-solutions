class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;

        int mn = -1;
        int max = -1;
        int cul = -1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i] < minK or nums[i] > maxK){
                cul = i;
            }
            if(nums[i] == minK){
                mn = i;
            }

            if(nums[i] == maxK){
                max = i;
            }

            long long smaller = min(mn, max);
            long long temp = smaller - cul;
            ans += (temp <= 0) ? 0: temp;
        }
        return ans;
    }
};