class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;

        long long power = abs(n);
        while(power){
            if(power % 2){
                ans = ans * x;
                power--;
            }else{
                x = x * x;
                power = power / 2;
            }
        }
        if(n < 0) ans = (double) (1.0)/ (double) (ans);
        return ans;
    }
};