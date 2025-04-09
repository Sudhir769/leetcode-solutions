class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;

        for(auto num:nums){
            if(num < k){
                return -1;
            }
            mp[num]++;
            if(num != k and mp[num] == 1){
                ans++;
            }
        }
        return ans;
    }
};