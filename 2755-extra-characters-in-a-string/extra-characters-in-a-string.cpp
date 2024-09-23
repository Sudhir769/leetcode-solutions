class Solution {
public:
    vector<int> dp;
    int solve(int i, int end, string &s, unordered_set<string> &st){
        if(i >= end){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int result = 1 + solve(i+1, end, s, st);

        for(int ind = i; ind < end; ind++){
            if(st.count(s.substr(i, ind-i+1))){
                result = min(result, solve(ind+1, end, s, st));
            }
        }
        return dp[i] = result;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        int end = s.length();
        unordered_set<string>st(dictionary.begin(), dictionary.end());
        dp.resize(end+1, -1);
        return solve(0, end, s, st);
    }
};