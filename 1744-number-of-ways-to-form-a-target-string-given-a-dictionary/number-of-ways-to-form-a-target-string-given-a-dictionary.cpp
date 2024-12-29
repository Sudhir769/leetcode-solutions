class Solution {
public:
    int m, k;
    int t[1001][10001];
    const int MOD = 1e9+7;

    int solve(int i, int j, vector<vector<long long>> &freq, string &target){
        if(i == m) return 1;
        if(j == k) return 0;

        if(t[i][j] != -1) return t[i][j];

        int notTake = solve(i, j+1, freq, target)%MOD;
        int take = (freq[target[i]-'a'][j] * solve(i+1, j+1, freq, target))%MOD;

        return t[i][j] = (take + notTake)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        m = target.length();
        k = words[0].length();

        memset(t, -1, sizeof(t));

        vector<vector<long long>> freq(26, vector<long long>(k));
        for(int col=0; col<k; col++){
            for(string &word:words){
                char ch = word[col];
                freq[ch-'a'][col]++;
            }
        }
        return solve(0, 0, freq, target);
    }
};