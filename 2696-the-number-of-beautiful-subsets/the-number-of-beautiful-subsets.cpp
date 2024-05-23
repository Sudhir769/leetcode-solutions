class Solution {
public:
    int result = 0;
    void solve(int i, vector<int>& nums, unordered_map<int, int>& st, int& k){
        if(i == nums.size()){
            result++;
            return;
        }
        solve(i+1, nums, st, k);
        if(!st[nums[i]-k] and !st[nums[i] + k]){
            st[nums[i]]++;
            solve(i+1, nums, st, k);
            st[nums[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>st;
        solve(0, nums, st, k);
        return result-1;
    }
};