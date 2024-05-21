class Solution {
public:
    vector<vector<int>>ans;
    int n = 0;
    void solve(int i, vector<int>temp, vector<int>& nums){
        if(i == n){
            ans.push_back(temp);
            return;
        }

        solve(i+1, temp, nums);
        temp.push_back(nums[i]);
        solve(i+1, temp, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        solve(0, {}, nums);
        return ans;
    }
};