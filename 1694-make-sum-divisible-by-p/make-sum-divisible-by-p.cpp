class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int sum = 0;
        for(auto num: nums){
            sum = (sum + num) % p;
        }
        int target = sum % p;

        if(target == 0) return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int result = n;
        int curr = 0;
        for(int i=0; i<n; i++){
            curr = (curr + nums[i]) % p;
            int rem = (curr - target + p) % p;

            if(mp.find(rem) != mp.end()){
                result = min(result, i - mp[rem]);
            }
            mp[curr] = i;
        }
        return result == n ? -1:result;
    }
};