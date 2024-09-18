class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int prefix = 0;
        mp[prefix] = 1;
        int result = 0;
        for(int i=0; i<n; i++){
            prefix += nums[i];
            int rem = prefix - goal;

            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }
            mp[prefix]++;
        }
        return result;
    }
};