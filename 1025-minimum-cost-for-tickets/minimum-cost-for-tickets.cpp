class Solution {
public:
    int n;
    vector<int> dp;
    int solve(int i, int n, vector<int>& days, vector<int>& costs){
        if(i >= days.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int day, week, month;
        day = costs[0] + solve(i+1, n, days, costs);

        int j = i;
        int max_day = days[i] + 7;
        while(j < n and days[j] < max_day){
            j++;
        }
        week = costs[1] + solve(j, n, days, costs);

        j = i;
        max_day = days[i] + 30;
        while(j < n and days[j] < max_day){
            j++;
        }
        month = costs[2] + solve(j, n, days, costs);

        return dp[i] = min({day, week, month});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        dp.resize(n, -1);
        return solve(0, n, days, costs);
    }
};