class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        long long i=0, j=0, ans=0;
        int cntMax = 0;
        while(j < n){
            cntMax += (nums[j] == mx);

            while(cntMax >= k){
                ans += n-j;
                cntMax -= (nums[i] == mx);
                i++;
            }
            j++;
        }
        return ans;
    }
};  