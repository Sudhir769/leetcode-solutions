class Solution {
public:
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;

        int result = 0, curr = 0;
        mp[0] = 1;
        for(auto num: nums){
            curr += num;
            int rem = curr - goal;

            if(mp.find(rem) != mp.end()){
                result += mp[rem];
            }

            mp[curr]++;
        }
        return result;
    }
};