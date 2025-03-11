class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string &text1, string &text2){
        if(i < 0 or j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j] = 1 + solve(i-1, j-1, text1, text2);
        }

        return dp[i][j] = max(solve(i-1, j, text1, text2), solve(i, j-1, text1, text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, text1, text2);
    }
};