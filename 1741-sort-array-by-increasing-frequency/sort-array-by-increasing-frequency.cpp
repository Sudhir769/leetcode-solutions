class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(auto num:nums){
            mp[num]++;
        }
        vector<vector<int>> vec;
        for(auto it:mp){
            vec.push_back({it.second, it.first});
        }

        auto lambda = [&](auto v1, auto v2){
            if(v1[0] < v2[0]) return true;
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return false;
        };
        sort(vec.begin(), vec.end(), lambda);
        vector<int> ans;
        for(auto it:vec){
            while(it[0]--){
                ans.push_back(it[1]);
            }
        }
        return ans;
    }
};