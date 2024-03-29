class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        long long l=0, r=0, ans=0;
        while(r < n){
            k -= (nums[r++] == mx);
            while(k==0) k += (nums[l++] == mx);
            ans += l;
        }
        return ans;
    }
};