class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1;
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            if((it.first > maxi and it.first > 0) and mp.find(-it.first) != mp.end()){
                maxi = it.first;
            }
        }
        return maxi;
    }
};