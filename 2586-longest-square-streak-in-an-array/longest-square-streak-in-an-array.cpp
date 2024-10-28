class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        sort(nums.begin(), nums.end());
        int maxi = 0;
        for(int i=0; i<n; i++){
            int root = (int) sqrt(nums[i]);
            if(root * root == nums[i] and mp.find(sqrt(nums[i])) != mp.end()){
                mp[nums[i]] = 1 + mp[sqrt(nums[i])];
            }else{
                mp[nums[i]] = 1;
            }
                maxi = max(maxi, mp[nums[i]]);
        }
        return maxi >= 2 ? maxi:-1;
    }
};