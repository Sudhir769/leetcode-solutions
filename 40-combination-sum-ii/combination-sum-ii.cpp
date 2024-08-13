class Solution {
public:
    void solve(int idx, vector<int>& candidates, int target, vector<vector<int>> &result, vector<int>&curr){
        if(target == 0){
            result.push_back(curr);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i > idx and candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target) break;

            curr.push_back(candidates[i]);
            solve(i+1, candidates, target-candidates[i], result, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, result, curr);
        return result;
    }
};