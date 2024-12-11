class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> intervals;
        for(int i=0; i<n; i++){
            intervals.push_back({nums[i]-k, nums[i]+k});
        }
        sort(intervals.begin(), intervals.end());
        // {{-1, 3}, {0, 4}, {2, 6}, {4, 8}}

        queue<vector<int>> q;

        int result = 0;
        for(auto interval:intervals){
            while(!q.empty() and q.front()[1] < interval[0]){
                q.pop();
            }
            q.push(interval);
            result = max(result, (int)q.size());
        }
        return result;
    }
};