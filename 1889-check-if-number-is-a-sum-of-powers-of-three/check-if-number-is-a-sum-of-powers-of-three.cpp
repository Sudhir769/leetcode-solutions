class Solution {
public:
    bool solve(int n, int p){
        if(n == 0) return true;
        if(pow(3, p) > n) return false;

        return solve(n - pow(3, p), p+1) or solve(n, p+1);
    }
    bool checkPowersOfThree(int n) {
        return solve(n, 0);
    }
};