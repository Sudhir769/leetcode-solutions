class Solution {
public:
    int t[100001];
    int MOD = 1e9+7;
    int solve(int length, int low, int high, int zero, int one){
        if(length > high) return 0;

        if(t[length] != -1) return t[length];
        
        int ans = 0;
        if(length >= low){
            ans += 1;
        }

        ans = (ans + solve(length + zero, low, high, zero, one))%MOD;
        ans = (ans + solve(length + one, low, high, zero, one))%MOD;

        return t[length] = ans%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(t, -1, sizeof(t));
        return solve(0, low, high, zero, one);
    }
};