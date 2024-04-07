class Solution {
public:
    int n=0;
    vector<vector<int>>dp;
    bool solve(int i, int open, string s){
        if(i==n){
            return open == 0;
        }
        if(dp[i][open] != -1){
            return dp[i][open];
        }

        bool ans = false;
        if(s[i] == '('){
            ans = ans or solve(i+1, open+1, s);
        }else if(s[i] == ')'){
            if(open > 0){
                ans = ans or solve(i+1, open-1, s);
            }
        }else{
            ans = (ans or (solve(i+1, open+1, s) or solve(i+1, open, s)));
            if(open > 0){
                ans = (ans or (solve(i+1, open-1, s)));
            }
        }
        return dp[i][open] = ans;
    }

    bool checkValidString(string s) {
        n = s.length();
        dp.resize(n+1, vector<int>(n+1, -1));
        return solve(0, 0, s);
    }
};