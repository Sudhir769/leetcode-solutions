class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string &s, string &p){
        if(i == 0 and j == 0) return true;
        if(j == 0 and i > 0) return false;
        if(i == 0 and j > 0) {
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] !=-1) return dp[i][j];
        
        if(s[i-1] == p[j-1] | p[j-1] == '?'){
            return dp[i][j] = solve(i-1, j-1, s, p);
        }

        if(p[j-1] == '*'){
            return dp[i][j] = solve(i-1, j, s, p) | solve(i, j-1, s, p);
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        dp.resize(n+1, vector<int>(m+1, 0));

        dp[0][0] = 1;
        for(int j=1; j<=m; j++){
            int fl = true;
            for(int k=1; k<=j; k++){
                if(p[k-1] != '*'){
                    fl = false;
                    break;
                }
            }
            dp[0][j] = fl;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == p[j-1] or p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};