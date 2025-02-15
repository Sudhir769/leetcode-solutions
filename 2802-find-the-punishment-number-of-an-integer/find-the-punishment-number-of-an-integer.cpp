class Solution {
public:
    bool check(int i, int curr, int sum){
        if(i == 0){
            return curr == sum;
        }

        if(curr > sum) return false;

        return check(i/10, curr + i%10, sum) ||
               check(i/100, curr + i%100, sum) ||
               check(i/1000, curr + i%1000, sum) ||
               check(i/10000, curr + i%10000, sum);
    }
    int punishmentNumber(int n) {
        
        int result = 0;
        for(int i=1; i<=n; i++){
            int sq = i*i;

            if(check(sq, 0, i) == true){
                result += sq;
            }
        }
        return result;
    }
};