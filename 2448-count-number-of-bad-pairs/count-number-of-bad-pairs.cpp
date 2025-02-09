class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n % 2 == 0) ? (n / 2) * (n - 1) : n * ((n - 1) / 2);
        unordered_map<int, int> mp;

        long long ans = 0;
        for(int i=0; i<n; i++){
            
            int curr = nums[i]-i;
            if(mp.find(curr) != mp.end()){
                ans += mp[curr];
            }
            mp[curr]++;
        }
        return abs(totalPairs - ans);
    }
};