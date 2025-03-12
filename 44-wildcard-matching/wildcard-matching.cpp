class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string &s, string &p){
        if(i < 0 and j < 0) return true;
        if(j < 0 and i >= 0) return false;
        if(i < 0 and j >= 0) {
            for(int k=0; k<=j; k++){
                if(p[k] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] !=-1) return dp[i][j];
        
        if(s[i] == p[j] or p[j] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p);
        }

        if(p[j] == '*'){
            return dp[i][j] = solve(i, j-1, s, p) | solve(i-1, j, s, p);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.resize(n+1, vector<int>(m+1, -1));
        return solve(n-1, m-1, s, p);
    }
};