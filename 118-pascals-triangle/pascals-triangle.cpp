class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        ans.push_back({1});
        if(numRows == 1) return ans;

        ans.push_back({1, 1});
        if(numRows == 2) return ans;


        for(int i=3; i<=numRows; i++){
            vector<int> prev = ans.back();

            vector<int> curr(1, 1);
            for(int j=1; j<i-1; j++){
                int digit = prev[j-1] + prev[j];
                curr.push_back(digit);
            }
            curr.push_back(1);
            ans.push_back(curr);
        }
        return ans;
    }
};