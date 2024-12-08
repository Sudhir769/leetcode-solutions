class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int bSearch(vector<vector<int>>&events, int endTime){
        int l = 0;
        int r = n-1;

        int result = n;
        while(l <= r){
            int mid = l + (r-l)/2;

            if(events[mid][0] > endTime){
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return result;
    }

    int solve(vector<vector<int>>&events, int i, int cnt){
        if(i >= n or cnt == 2){
            return 0;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];

        int nextIndex = bSearch(events, events[i][1]);
        int take = events[i][2] + solve(events, nextIndex, cnt+1);
        int notTake = solve(events, i+1, cnt);

        return dp[i][cnt] = max(take, notTake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());
        dp.resize(100001, vector<int> (3, -1));

        int count = 0;
        return solve(events, 0, count);
    }
};