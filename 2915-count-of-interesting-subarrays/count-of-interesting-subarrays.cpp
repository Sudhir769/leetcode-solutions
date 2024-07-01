class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        unordered_map<long long, long long> mp;
        long long prefix = 0, ans = 0, n = nums.size();
        mp[0]++;
        for(int i=0; i<n; i++){
            if(nums[i] % mod == k){
                prefix++;
            }
            prefix %= mod;
            ans += mp[(prefix-k+mod)%mod];
            mp[prefix]++;
        }
        return ans;
    }
};