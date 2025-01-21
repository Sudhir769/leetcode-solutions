class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        long long upperRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        long long lowerRowSum = 0, minSecondRobotPoints = LONG_LONG_MAX;
        
        for(int col=0; col<n; col++){
            upperRowSum -= grid[0][col];
            minSecondRobotPoints = min(minSecondRobotPoints, max(upperRowSum, lowerRowSum));
            lowerRowSum += grid[1][col];
        }
        return minSecondRobotPoints;
    }
};