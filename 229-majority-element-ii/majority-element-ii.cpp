class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        int minFreq = (int)n/3+1;
        
        for(auto it:nums){
            mp[it]++;
            if(mp[it] == minFreq){
                ans.push_back(it);
            }
            if(ans.size() == 2) break;
        }
        // if(ans.size() == 0) return {-1};
        return ans;
    }
};