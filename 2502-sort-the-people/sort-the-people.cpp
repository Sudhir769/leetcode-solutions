class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mp;
        int n = names.size();

        for(int i=0; i<n; i++){
            mp[heights[i]] = names[i];
        }
        sort(heights.rbegin(), heights.rend());
        vector<string>ans;

        for(int i=0; i<n; i++){
            ans.push_back(mp[heights[i]]);
        }
        return ans;
    }
};