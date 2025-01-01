class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int result = INT_MIN;

        int total_ones = count(s.begin(), s.end(), '1');

        int ones=0;
        int zeros=0;
        int right_ones=0;

        for(int i=0; i<n-1; i++){
            if(s[i]=='1'){
                ones++;
            }else{
                zeros++;
            }
            right_ones = total_ones - ones;

            result = max(result, zeros+right_ones);
        }
        return result;
    }
};