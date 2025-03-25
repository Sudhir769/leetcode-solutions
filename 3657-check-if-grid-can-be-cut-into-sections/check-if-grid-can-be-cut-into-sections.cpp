class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i][0] < ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> hor, ver;

        for(auto &cor:rectangles){
            int x1 = cor[0];
            int y1 = cor[1];
            int x2 = cor[2];
            int y2 = cor[3];

            hor.push_back({x1, x2});
            ver.push_back({y1, y2});
        }

        vector<vector<int>> result1 = merge(hor);
        if(result1.size() >= 3){
            return true;
        }

        vector<vector<int>> result2 = merge(ver);
        return result2.size() >= 3;
    }
};