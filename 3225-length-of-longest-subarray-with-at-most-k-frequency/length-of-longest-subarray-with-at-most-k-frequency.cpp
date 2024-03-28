class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        int i=0, j=0, ans=1;
        while(i<n and j<n){
            mp[nums[i]]++;
            while(mp[nums[i]] > k){
                mp[nums[j]]--;
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};